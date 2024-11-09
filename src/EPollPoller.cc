#include "EPollPoller.hpp"
#include "Logger.hpp"

using namespace goa::ev;


EPollPoller::EPollPoller(EventLoop* loop):
                        loop_(loop),
                        events_(128),
                        epollfd_(epoll_create1(EPOLL_CLOEXEC))
{
    if(epollfd_ ==-1 ){
        SYSFATAL("Epoller::epoll_create1");        
    }
}

EPollPoller::~EPollPoller(){
    close(epollfd_);
}

// 获取有事件发生的channel
void EPollPoller::poll(ChannelList& activeChannels){
    loop_->assertInLoopThread();
    int maxEvents = static_cast<int>(events_.size());
    // 得到触发的event个数，并将epoll_event写入events_缓冲区，最多一次获取128个(初始参数，可调)
    int nEvents = epoll_wait(epollfd_, events_.data(), maxEvents, -1);
    if (nEvents == -1) {
        if (errno != EINTR) {           // signal: interrupted sys call
            SYSERR("EPollPoller::epoll_wait");
        }
    }
    else if (nEvents > 0){
        // 得到触发的event个数，并依次访问操作
        for (int i = 0; i < nEvents; i++){
            // epoll_event中的epoll_data_t中存对应Channel的指针
            auto channelPtr = static_cast<Channel*>(events_[i].data.ptr);
            channelPtr->setRevents(events_[i].events);  //发生的事件类型
            activeChannels.push_back(channelPtr);   //把该Channel放入活跃队列中
        }
        if(nEvents == maxEvents){
            events_.resize(2 * events_.size()); // 扩容
        }
    }
}


// 更新epoll中管理的channel
void EPollPoller::updateChannel(Channel* channel){
    loop_->assertInLoopThread();
    int op = 0;
    // 更新Channel的几种情况
    if(!channel -> pooling ){ 
        // 如果当前Channel没有被管理，那么这里的更新操作一定是要添加到epoll管理
        assert(!channel -> isNoneEvents()); // 既然是新的待添加管理的对象，那么一定设置过想要监听的操作类型
        op = EPOLL_CTL_ADD;
        channel -> pooling = true;
    }
    else if(!channel -> isNoneEvents()){ 
        // 如果当前Channel已经被管理，但是需要更新监听的操作类型
        op = EPOLL_CTL_MOD;
    }
    else {
        // 如果已经被管理  但是要监听的事件为空
        op = EPOLL_CTL_DEL;
        channel -> pooling = false;
    }
    updateChannel(op,channel);

}


// epoll监听的每个fd都有自己的epoll_event结构体 一般来说结构体保存了监听的事件类型和data信息 data一般保存的是fd
// 在注册事件的时候，epoll_event结构体中的data改为channel指针，channel指针包含了fd及感兴趣的事件信息
// 通过epoll_wait函数 获取fd发生的事件类型 及管理它的channel指针
void EPollPoller::updateChannel(int op,Channel* channel){
    epoll_event epEv;
    epEv.events = channel -> events();
    epEv.data.ptr = channel;
    if (epoll_ctl(epollfd_, op, channel->fd(), &epEv) == -1) {
        SYSERR("EPollPoller::epoll_ctl");
    }
}