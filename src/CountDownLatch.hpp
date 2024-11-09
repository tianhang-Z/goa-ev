#pragma once

#include <mutex>
#include <condition_variable>

#include "noncopyable.hpp"

namespace goa {

namespace ev {

/*
实现线程同步的机制
适用于 等待多个线程完成任务
*/
class CountDownLatch : noncopyable {

public:
    explicit CountDownLatch(int count) 
        : count_(count) {}

    void count(){
        std::lock_guard<std::mutex> lock(mutex_);
        count_--;
        if(count_<=0){
            cond_.notify_all();           //唤醒所有等待线程
        }
    }

    void wait(){
        std::unique_lock<std::mutex> lock(mutex_);
        while(count_>0){
            cond_.wait(lock);        //阻塞时会释放锁 并进入等待状态
        }
    }
    

private:
    int count_;      //需要等待的事件数量
    std::mutex mutex_;
    //cond_结合mutex unique_lock wait notify_all   
    std::condition_variable cond_;    

};

}// namespace ev
}// namespace goa