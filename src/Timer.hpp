#pragma once

#include <cassert>

#include "Callbacks.hpp"
#include "Timestamp.hpp"
#include "noncopyable.hpp"

namespace goa {

namespace ev {

/*
timer对象在timerqueue中被管理
Timer有自己回调函数 第一次触发时间和循环触发的间隔
*/
class Timer : noncopyable {
 public:
  Timer(TimerCallback callback, Timestamp when, Nanoseconds interval)
      : callback_(callback),
        when_(when),
        interval_(interval),
        repeat_(interval_ > Nanoseconds::zero()),
        canceled_(false) {}

  void run() {
    if (callback_) callback_();
  }

  bool repeat() const { return repeat_; }

  bool expired(Timestamp now) const { return now >= when_; }

  Timestamp when() const { return when_; }

  void restart() {
    assert(repeat_);
    when_ += interval_;  //更新下一次的触发时间
  }

  void cancel() {
    assert(!canceled_);
    canceled_ = true;
  }

  bool canceled() const { return canceled_; }

 private:
  TimerCallback callback_;
  Timestamp when_;              //第一次触发时间
  const Nanoseconds interval_;  //周期触发间隔
  bool repeat_;
  bool canceled_;
};

}  // namespace ev

}  // namespace goa