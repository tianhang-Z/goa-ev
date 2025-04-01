#pragma once

#include "Callbacks.hpp"
#include "Channel.hpp"
#include "InetAddress.hpp"
#include "noncopyable.hpp"

namespace goa {

namespace ev {

class EventLoop;
class InetAddress;

/*
用于客户端  申请一个socketfd 并注册handlerwrite了回调函数
析构时关闭socketfd
*/
class Connector : noncopyable {
 public:
  Connector(EventLoop* loop, const InetAddress& peer);
  ~Connector();

  void start();

  void setNewConnectionCallback(const NewConnectionCallback& callback);
  void setErrorCallback(const ErrorCallback& callback);

 private:
  void handleWrite();

  EventLoop* loop_;
  const InetAddress peer_;
  const int sockfd_;
  bool connected_;
  bool started_;
  Channel channel_;
  NewConnectionCallback newConnectionCallback_;
  ErrorCallback errorCallback_;
};

}  // namespace ev

}  // namespace goa