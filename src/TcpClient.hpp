#pragma once

#include "Callbacks.hpp"
#include "Connector.hpp"
#include "Timer.hpp"

namespace goa {

namespace ev {

/*
含有一个connector指针  并实现了newConnection 传递给connector
*/
class TcpClient : noncopyable {

public:
    TcpClient(EventLoop* loop, const InetAddress& peer);
    ~TcpClient();

    void setConnectionCallback(const ConnectionCallback&);
    void setMessageCallback(const MessageCallback&);
    void setWriteCompleteCallback(const WriteCompleteCallback&);
    void setErrorCallback(const ErrorCallback&);

    void start();

private:
    void retry();
    //传给connector的回调
    void newConnection(int connfd, const InetAddress& local, const InetAddress& peer);      
    void closeConnection(const TcpConnectionPtr& conn);

    using ConnectorPtr = std::unique_ptr<Connector>;

    EventLoop* loop_;
    bool connected_;
    const InetAddress peer_;
    Timer* retryTimer_;
    ConnectorPtr connector_;
    TcpConnectionPtr connection_;
    ConnectionCallback connectionCallback_;     // 额外的回调 可用于自定义功能
    MessageCallback messageCallback_;
    WriteCompleteCallback writeCompleteCallback_;
};

} // namespace ec

} // namespace goa