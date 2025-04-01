#pragma once

#include <memory>
#include <set>

#include "Channel.hpp"
#include "Timer.hpp"
#include "Timestamp.hpp"
#include "noncopyable.hpp"

namespace goa {

namespace ev {

/*
TimerQueue 属于一个Eventloop 有自己的timerfd_(放在channel中) 利用eventloop初始化
Queue使用set<pair<Timestamp, Timer*>>来存储若干Timer  便于查询和删改
可以认识其是一个优先队列 队首的始终是最先到期的Timer
因此timerfd_只需服务队首的timer

timerfd 是一种用于定时器的文件描述符，
它允许程序通过读取文件描述符来等待定时器超时并触发事件
timerfd_create：创建一个定时器并返回一个文件描述符。
timerfd_settime：设置定时器的时间和行为（一次性或周期性定时器）。
timerfd_gettime：获取当前定时器的剩余时间。
read：从 timerfd 文件描述符读取时，会获取定时器已经触发的次数
*/
class TimerQueue : noncopyable {
 public:
  explicit TimerQueue(EventLoop* loop);
  ~TimerQueue();

  Timer* addTimer(TimerCallback callback, Timestamp when, Nanoseconds interval);
  void cancelTimer(Timer* timer);

 private:
  using Entry = std::pair<Timestamp, Timer*>;
  using TimerList = std::set<Entry>;

  void handleRead();
  std::vector<Entry> getExpired(Timestamp now);

 private:
  EventLoop* loop_;
  const int timerfd_;
  Channel timerChannel_;
  TimerList timers_;
};

}  // namespace ev

}  // namespace goa