#include "Connector.hpp"

#include "EventLoop.hpp"
#include "Logger.hpp"

using namespace goa::ev;

namespace {

int createSocket() {
  int ret = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
  if (ret == -1) {
    SYSFATAL("Connector createSocket");
  }
  return ret;
}

}  // namespace

Connector::Connector(EventLoop* loop, const InetAddress& peer)
    : loop_(loop),
      peer_(peer),
      sockfd_(createSocket()),
      connected_(false),
      started_(false),
      channel_(loop, sockfd_) {
  channel_.setWriteCallback([this]() { handleWrite(); });
}

Connector::~Connector() {
  if (!connected_) {
    close(sockfd_);
  }
}

// 请求连接
void Connector::start() {
  loop_->assertInLoopThread();
  assert(!started_);
  started_ = true;

  int ret = connect(sockfd_, peer_.getSockaddr(), peer_.getSocklen());
  if (ret == -1) {
    if (errno != EINPROGRESS) {  // 连接失败
      handleWrite();
    } else {  // 连接正在进行中
      channel_.enableWrite();
    }
  } else
    handleWrite();  // 连接成功
}

void Connector::setNewConnectionCallback(
    const NewConnectionCallback& callback) {
  newConnectionCallback_ = callback;
}
void Connector::setErrorCallback(const ErrorCallback& callback) {
  errorCallback_ = callback;
}

void Connector::handleWrite() {
  loop_->assertInLoopThread();
  assert(started_);

  loop_->removeChannel(&channel_);
  int err;
  socklen_t len = sizeof(err);
  int ret =
      getsockopt(sockfd_, SOL_SOCKET, SO_ERROR, &err, &len);  // 获取错误码
  if (ret == 0) {
    errno = err;
  }

  // err=0则连接成功
  if (errno != 0) {  // connect错误就执行错误处理
    SYSERR("Connector handleWrite connect");
    if (errorCallback_) {
      errorCallback_();
    }
  } else if (newConnectionCallback_) {  // connect成功
    sockaddr_in addr;
    len = sizeof(addr);
    ret = getsockname(sockfd_, reinterpret_cast<sockaddr*>(&addr), &len);
    if (ret == -1) {
      SYSERR("Connection getsockname");
    }
    InetAddress local;
    local.setAddress(addr);

    connected_ = true;
    newConnectionCallback_(sockfd_, local, peer_);
  }
}