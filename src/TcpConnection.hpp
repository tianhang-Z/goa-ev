#pragma once

#include <any>

#include "Buffer.hpp"
#include "Callbacks.hpp"
#include "Channel.hpp"
#include "InetAddress.hpp"
#include "noncopyable.hpp"

namespace goa {

namespace ev {

class EventLoop;

/*
利用channel实现TCP连接的封装 为channel设置回调函数
并设置额外的回调自定义处理事件，利用eventloop监听
封装了一个已建立的TCP连接，以及控制该TCP连接的方法（连接建立和关闭和销毁），
以及该连接发生的各种事件（读/写/错误/连接）对应的处理函数，
以及这个TCP连接的服务端和客户端的套接字地址信息等。

Acceptor对服务器监听套接字fd及其相关方法进行封装（监听、接受连接、分发连接给SubEventLoop等），

TcpConnection对连接套接字fd及其相关方法进行封装（读消息事件、发送消息事件、连接关闭事件、错误事件等）。

当输出缓冲区的数据超过设置的高水位标记时，会调用 highWaterMarkCallback_。
这是一个流量控制机制，用于在数据积压时采取措施。
*/
class TcpConnection : noncopyable,
                      public std::enable_shared_from_this<TcpConnection> {
 public:
  TcpConnection(EventLoop* loop, int sockfd, const InetAddress& local,
                const InetAddress& peer);
  ~TcpConnection();

  void setMessageCallback(const MessageCallback& callback);
  void setWriteCompleteCallback(const WriteCompleteCallback& callback);
  void setHighWaterMarkCallback(const HighWaterMarkCallback& callback,
                                size_t mark);
  void setCloseCallback(const CloseCallback& callback);

  void connectEstablished();
  bool connected() const;
  bool disconnected() const;

  const InetAddress& local() const;
  const InetAddress& peer() const;
  std::string name() const;

  void setContext(const std::any& context);
  const std::any& getContext() const;
  std::any& getContext();

  void send(std::string_view data);
  void send(const char* data, size_t len);
  void send(Buffer& buffer);

  void shutdown();  // 半关闭，关闭服务端写，保留读
  void forceClose();

  void stopRead();
  void startRead();
  bool isReading();

  const Buffer& inputBuffer() const;
  const Buffer& outputBuffer() const;

 private:
  void handleRead();
  void handleWrite();
  void handleClose();
  void handleError();

  void sendInLoop(const char* data, size_t len);
  void sendInLoop(const std::string& message);
  void shutdownInLoop();
  void forceCloseInLoop();

  int stateAtomicGetAndSet(int newState);

  EventLoop* loop_;
  const int sockfd_;
  Channel channel_;
  int state_;
  InetAddress local_;
  InetAddress peer_;
  Buffer inputBuffer_;
  Buffer outputBuffer_;
  size_t highWaterMark_;

  std::any context_;
  // channel_自身有回调  此处可为连接设置额外的回调
  MessageCallback messageCallback_;
  WriteCompleteCallback writeCompleteCallback_;
  HighWaterMarkCallback highWaterMarkCallback_;
  CloseCallback closeCallback_;
};

}  // namespace ev

}  // namespace goa