#include <syscall.h>
#include <signal.h>
#include <sys/eventfd.h>

#include "EventLoop.hpp"
#include "Logger.hpp"

using namespace goa::ev;

namespace {

__thread EventLoop* t_Eventloop = nullptr; // thread local variable

pid_t internalGettid() {
    return static_cast<pid_t>(syscall(SYS_gettid));
}

/*
当进程尝试向一个已经关闭写端的管道或套接字（例如，在网络通信中对方已经关闭连接）发送数据时。
默认情况下，如果程序没有处理该信号，操作系统会终止进程，这可能导致不希望的结果。
在事件循环中，我们可能会进行网络通信，例如使用套接字进行数据传输。如果对方关闭了连接，
但程序仍然尝试向其发送数据，就会产生 SIGPIPE 信号。为了避免进程终止，可以通过忽略 SIGPIPE 信号来解决问题。
*/
class IgnoreSigPipe {
public:
    IgnoreSigPipe() {
        signal(SIGPIPE, SIG_IGN);
    }
};
IgnoreSigPipe ignore;

} //anonymous namespace


/*
eventloop创建时绑定其所在的线程pid
设置用于唤醒线程的wakeupfd_
*/
EventLoop::EventLoop():
            tid_(internalGettid()),             
            quit_(false),
            doingPendingTasks_(false),
            poller_(this),
            wakeupfd_(eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC)),
            wakeupChannel_(this, wakeupfd_),
            timerQueue_(this)
{
    // 检查用于事件通知的文件描述符是否被正确创建
    if (wakeupfd_ == -1) {
        SYSFATAL("EventLoop::eventfd");
    }

    wakeupChannel_.setReadCallback([this](){handleRead();});            //绑定回调函数
    wakeupChannel_.enableRead();             //这里会将wakeupchannel_加入epoll中监听

    assert(t_Eventloop == nullptr);
    t_Eventloop = this;  //  one loop per thread
}


EventLoop::~EventLoop(){
    wakeupChannel_.disableAll();  // 移除对wakeupChannel_的监听
    close(wakeupfd_);  // 释放资源
    assert(t_Eventloop == this);
    t_Eventloop = nullptr;
}

// 开启循环
void EventLoop::loop(){
    assertInLoopThread();
    TRACE("EventLoop {} start polling", static_cast<void*>(this));
    quit_ = false;
    while (!quit_) {
        activeChannels_.clear();
        poller_.poll(activeChannels_); // 得到触发的event，装载入activeChannels_中
        for (auto channelPtr : activeChannels_) {
            channelPtr->handleEvents();
        }
        // 这里的关键是如何使得线程不会被阻塞在epoll_wait，而能顺利执行后续任务
        //wakeup() 向wakeupfd_写入数据 则唤醒了epoll_wait
        doPendingTasks();                    
    }
    TRACE("EventLoop {} quit", static_cast<void*>(this));
}

// 退出循环
void EventLoop::quit(){
    assert(!quit_);
    quit_ = true;
    if(!isInLoopThread()){
        wakeup();                        
    }
}


// 在当前loop中执行   执行当前任务 或者是执行队列中的任务
void EventLoop::runInLoop(const Task& task){
    if(isInLoopThread()){                 //如果是初始线程 则执行任务
        task();
    }                     
    else queueInLoop(task);   //若不是 则任务加入队列 并唤醒初始线程 
}
void EventLoop::runInLoop(Task&& task){
    if (isInLoopThread()) {
        task();
    }
    else queueInLoop(std::move(task));
}



// 把任务放入队列中，唤醒loop所在的线程执行task
void EventLoop::queueInLoop(const Task& task){
    {
        std::lock_guard<std::mutex> guard(mutex_);      
        pendingTasks_.push_back(task);   //保证队列的访问线程安全
    }
    // 如果不在循环线程，就唤醒循环线程去处理任务；如果在循环线程，并且正在处理任务，那么同样唤醒
    if(!isInLoopThread() || doingPendingTasks_){
        wakeup();
    }
}
void EventLoop::queueInLoop(Task&& task){
   {
        std::lock_guard<std::mutex> guard(mutex_);
        pendingTasks_.push_back(std::move(task));
    }
    if (!isInLoopThread() || doingPendingTasks_) {
        wakeup();
    }
}


// 定时器相关
Timer* EventLoop::runAt(Timestamp when, TimerCallback callback){
    //添加一个定时器
    return timerQueue_.addTimer(std::move(callback), when, Milliseconds::zero());
}
Timer* EventLoop::runAfter(Nanoseconds interval, TimerCallback callback){
    return runAt(clock::now() + interval, std::move(callback));

}
Timer* EventLoop::runEvery(Nanoseconds interval, TimerCallback callback){
    return timerQueue_.addTimer(std::move(callback), clock::now() + interval, interval);
}
void EventLoop::cancelTimer(Timer* timer){
    timerQueue_.cancelTimer(timer);
}


// 通过wakeupfd_/wakeupChannel_唤醒loop所在的线程
// 写入一个数，有了事件，结束loop中的epoll_wait阻塞
void EventLoop::wakeup(){
    uint64_t one = 1;
    ssize_t n = write(wakeupfd_, &one, sizeof(one));
    if (n != sizeof(one)) {
        SYSERR("EventLoop::wakeup() should write() {} bytes but", sizeof(one), n);
    }
}

// 通过epollpoller更新channel
void EventLoop::updateChannel(Channel* channel){
    assertInLoopThread();
    poller_.updateChannel(channel);
}
void EventLoop::removeChannel(Channel* channel){
    assertInLoopThread();
    channel->disableAll();
}



// 判断EventLoop对象是否在自己的线程里。可能在别的线程中被调用
void EventLoop::assertInLoopThread() {
    assert(isInLoopThread());
}
void EventLoop::assertNotInLoopThread() {
    assert(!isInLoopThread());
}
bool EventLoop::isInLoopThread() {
    return tid_ == internalGettid();
}



// 执行上层添加的任务
void EventLoop::doPendingTasks(){
    assertInLoopThread();
    std::vector<Task> tasks;
    {
        std::lock_guard<std::mutex> guard(mutex_);
        tasks.swap(pendingTasks_); // 将原队列对象置换出来，减少临界区范围 这边处理时不影响另一边添加任务
    }
    doingPendingTasks_ = true;
    for (auto& task : tasks) {
        task();
    }
    doingPendingTasks_ = false;
}



// 与wakeupfd_/wakeupChannel_绑定的回调
void EventLoop::handleRead(){
    uint64_t one;   //处理wakeupfd_中的数据
    ssize_t n = read(wakeupfd_, &one, sizeof(one));
    if (n != sizeof(one)) {
        SYSERR("EventLoop::handleRead() should read() {} bytes, but {}", sizeof(one), n);
    }
}

