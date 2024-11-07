#pragma once

#include "noncopyable.hpp"
#include "EventLoop.hpp"

#include <functional>
#include <memory>

namespace goa {

namespace ev {

class EventLoop;

/*
channel封装了某个fd 及其感兴趣的事件和发送的事件类型
Channel总是作为另一个对象的成员，比如Timer、Acceptor、TCPConnection
*/
class Channel : noncopyable {

private:
    using ReadCallback  = std::function<void()>;
    using WriteCallback = std::function<void()>;
    using CloseCallback = std::function<void()>;
    using ErrorCallback = std::function<void()>;

public:
    Channel(EventLoop* loop,int fd);
    ~Channel();

public:
    //设置处理函数
    void setReadCallback(const ReadCallback& callback);
    void setWriteCallback(const WriteCallback& callback);
    void setCloseCallback(const CloseCallback& callback);
    void setErrorCallback(const ErrorCallback& callback);

    // TODO
    void handleEvents();
    int fd() const;                         //获取fd
    bool isNoneEvents() const;   
    unsigned events() const;
    void setRevents(unsigned);                //将fd实际发生的事件类型记录到channel中的revents_中
    void tie(const std::shared_ptr<void>& obj);

    void enableRead();               //将fd及其感兴趣事件类型注册到epoll事件监听器 或移除
    void enableWrite();
    void disableRead();
    void disableWrite();
    void disableAll();

    bool isReading() const;         
    bool isWriting() const;

public:
    bool pooling;         //channel是否被epoll管理

private:
    EventLoop* loop_;          // fd 属于的eventloop
    int fd_;        // channel 照看的fd
    std::weak_ptr<void> tie_;
    bool tied_;
    unsigned events_;           //fd感兴趣的事件类型
    unsigned revents_;          //fd实际发生的事件类型
    bool handlingEvents_;

    ReadCallback readCallback_;               //fd各类型的处理函数  类似函数指针 但更安全、更灵活
    WriteCallback writeCallback_;
    CloseCallback closeCallback_;
    ErrorCallback errorCallback_;

private:

    // TODO   利用loop_对象注册或注销
    void update();
    void remove();

    void handleEventWithGuard();
};

} // namespace ev

} // namespace goa