#pragma once

#include <thread>

#include "CountDownLatch.hpp"

namespace goa{

namespace ev{

class EventLoop;

/*
EventLoopThread用于启动一个新的线程，该线程中创建EventLoop对象并运行
loop_指向其创建的线程中的eventloop
每个eventloop都有绑定的线程
*/
class EventLoopThread: noncopyable{

public:
    EventLoopThread();
    ~EventLoopThread();

   //创建一个新的线程 线程中创建EventLoop对象并运行 
    EventLoop* startLoop();      

private:
    void runInThread();  

    bool started_;
    EventLoop* loop_;  //记录startLoop()创建的EventLoop对象
    std::thread thread_;
    CountDownLatch latch_;
};

} // namespace ev

}// namespace goa