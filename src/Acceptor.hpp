#pragma once 

#include "noncopyable.hpp"
#include "InetAddress.hpp"
#include "Channel.hpp"
#include "Callbacks.hpp"

namespace goa{

namespace ev{

class EventLoop;

/*
Accetpor封装了服务器监听套接字fd以及相关处理方法 
对其他类的方法调用进行封装
*/
class Acceptor : noncopyable{

public:
    Acceptor(EventLoop*, const InetAddress&);
    ~Acceptor();

    bool listening() const;

    //开启监听acceptfd，将acceptfd_及其回调函数写到acceptChannel中，并注册到eventloop的epollpoller中
    void listen();  

    void setNewConnectionCallback(const NewConnectionCallback& callback);

private:
    /*
    acceptfd_的回调函数,接受新连接，
    */
    void handleRead();
    
    bool listening_;
    EventLoop *loop_;         // 指向的是主Reactor的EventLoop对象
    const int acceptfd_;          //服务器监听套接字的文件描述符
    Channel acceptChannel_;
    InetAddress local_;
    NewConnectionCallback newConnectionCallback_;   //
};

} // namespace ev

} // namespace goa