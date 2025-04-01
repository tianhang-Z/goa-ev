#include "TimerQueue.hpp"

#include <sys/timerfd.h>

#include <chrono>

#include "EventLoop.hpp"
#include "Logger.hpp"

using namespace goa::ev;

namespace {

int timerfdCreate() {
  int fd = timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
  if (fd == -1) {
    SYSFATAL("timerfd_create");
  }
  return fd;
}

void timerfdRead(int fd) {
  uint64_t val;
  ssize_t n = read(fd, &val, sizeof(val));
  if (n != sizeof(val)) {
    ERROR("timerfdRead get length{}, not {}", n, sizeof(val));
  }
}

/*
struct timespec {
    time_t tv_sec;  // 秒数
    long tv_nsec;   // 纳秒数
};

struct itimerspec {
    struct timespec it_interval;  // 定时器重复间隔时间
    struct timespec it_value;     //
定时器初次到期时间，默认以以相对时间的方式存储
};
*/
// 返回从当前时间点到指定时间戳之间的时间间隔
timespec durationFromNow(Timestamp when) {
  timespec ret;
  Nanoseconds ns = when - clock::now();

  using namespace std::chrono;
  if (ns < 1ms) ns = 1ms;

  // 分别设置秒数和纳秒数
  ret.tv_sec = static_cast<time_t>(ns.count() / std::nano::den);
  ret.tv_nsec = ns.count() % std::nano::den;
  return ret;
}

void timerfdSet(int fd, Timestamp when) {
  itimerspec oldtime, newtime;
  memset(&oldtime, 0, sizeof(itimerspec));
  memset(&newtime, 0, sizeof(itimerspec));
  newtime.it_value = durationFromNow(when);  //存储when到now的时间间隔

  int ret = timerfd_settime(fd, 0, &newtime, &oldtime);
  if (ret == -1) {
    SYSERR("timerfd_settime");
  }
}

}  // anonymous namespace

TimerQueue::TimerQueue(EventLoop *loop)
    : loop_(loop), timerfd_(timerfdCreate()), timerChannel_(loop, timerfd_) {
  loop_->assertInLoopThread();
  // 定时器触发时，timerFd_会有可读事件，交由handleRead来处理
  timerChannel_.setReadCallback([this]() { this->handleRead(); });
  timerChannel_.enableRead();
}

TimerQueue::~TimerQueue() {
  for (auto &p : timers_) {
    delete p.second;
  }
  close(timerfd_);
}

Timer *TimerQueue::addTimer(TimerCallback callback, Timestamp when,
                            Nanoseconds interval) {
  Timer *timer = new Timer(std::move(callback), when, interval);
  loop_->runInLoop([this, when, timer]() {
    // 注意set是升序的 insert之后 set的第一个元素就是时间最临界的
    auto checkPair = timers_.insert({when, timer});
    assert(checkPair.second);
    // insert 的返回值是一个 pair，其中包含了两个元素：
    //        插入是否成功：一个布尔值，表示元素是否成功插入。
    //        指向插入元素的迭代器：指向插入元素的位置。
    // 设置定时器触发时刻为最近的时间点
    if (timers_.begin() == checkPair.first) {
      // 新插入的元素若排在set的第一个 则利用其设置timerfd_
      timerfdSet(timerfd_, when);
    }
  });
  return timer;
}

// 取消定时器  并从TimerQueue中删除
void TimerQueue::cancelTimer(Timer *timer) {
  loop_->runInLoop([this, timer]() {
    timer->cancel();
    timers_.erase({timer->when(), timer});
    delete timer;
  });
}

void TimerQueue::handleRead() {
  loop_->assertInLoopThread();
  timerfdRead(timerfd_);  // 将可读的内容读取一下从而清空缓冲区

  Timestamp now(clock::now());
  for (auto &e : getExpired(now)) {
    Timer *timer = e.second;
    assert(timer->expired(now));  // now >= when

    if (!timer->canceled()) {
      timer->run();  // callback
    }
    if (!timer->canceled() && timer->repeat()) {
      timer->restart();  // 重启定时器
      // 如果需要重复，那就按interval设置新的时间戳，并加入定时器管理集合
      e.first = timer->when();
      timers_.insert(e);
    } else
      delete timer;  //否则说明已经被取消了，直接丢弃
  }
  // 如果还有未到时间的定时器，那就把最近的时间点作为触发时间点
  // 向内核中注册的定时器其实只有一个，定时器队列由网络库维护
  if (!timers_.empty()) {
    timerfdSet(timerfd_, timers_.begin()->first);
  }
}

// 将已过期的定时器从set中移除，并返回已过期的Entry数组
// 在hanldleRead中 会处理过期的时钟  若需要repeat会重新加入set
// std::set 是一个有序容器 默认升序
std::vector<TimerQueue::Entry> TimerQueue::getExpired(Timestamp now) {
  using namespace std::chrono;
  Entry endEntry(now + 1ns, nullptr);
  std::vector<Entry> ret;

  auto end = timers_.lower_bound(endEntry);  // 找到第一个大于endEntry的元素
  ret.assign(timers_.begin(), end);          // 复制到ret中
  timers_.erase(timers_.begin(), end);  // 删除已过期的定时器
  return ret;
}