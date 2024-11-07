#pragma once

#include <vector>
#include <sys/epoll.h>

#include "noncopyable.hpp"
#include "EventLoop.hpp"

namespace goa {

namespace ev {

class EventLoop;
class Channel;

/*
负责监听fd  

*/
class EPollPoller: noncopyable {

public:
    using ChannelList = std::vector<Channel*>;    //epoll可有多个channel  每个channel负责一个fd

    explicit EPollPoller(EventLoop* loop);
    ~EPollPoller();
 
    void poll(ChannelList& activeChannels);         //获取有事件发生的channel 存入activeChannels
    void updateChannel(Channel* channel);

private:
    void updateChannel(int op, Channel* channel);
    EventLoop* loop_;   //所属的eventloop
    std::vector<epoll_event> events_;           //
    int epollfd_;  

};

} // namespace ev

} // namespace mudong