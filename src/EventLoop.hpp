#pragma once 

#include <atomic>

#include "Timer.hpp"
#include "TimerQueue.hpp"
#include "EPollPoller.hpp"

/*
采用 One Loop Per Thread
循环 调用EPollPoller的poll()方法 获取发生事件的activeChannel
之后需要调用channel的handle_event()方法处理事件

每一个EventLoop都绑定了一个线程   每一个核的线程负责循环监听一组文件描述符的集合

*/

namespace goa{

namespace ev{

class EventLoop :noncopyable{

public:
    EventLoop();
    ~EventLoop();



}

}//namespace ev

}//namespace goa