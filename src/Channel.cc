#include "Channel.hpp"

#include <sys/epoll.h>

#include <cassert>

#include "EventLoop.hpp"

using namespace goa::ev;

Channel::Channel(EventLoop* loop, int fd)
    : pooling(false),
      loop_(loop),
      fd_(fd),
      tied_(false),
      events_(0),
      revents_(0),
      handlingEvents_(false) {}

Channel::~Channel() {
  assert(!handlingEvents_ && "handling Events while Channel destructing");
}

void Channel::setReadCallback(const ReadCallback& callback) {
  readCallback_ = callback;
}
void Channel::setWriteCallback(const WriteCallback& callback) {
  writeCallback_ = callback;
}
void Channel::setCloseCallback(const CloseCallback& callback) {
  closeCallback_ = callback;
}
void Channel::setErrorCallback(const ErrorCallback& callback) {
  errorCallback_ = callback;
}

/**
 * Channel总是作为另一个对象的成员，比如Timer、Acceptor、TCPConnection
 * TcpConnection用shared_ptr来管理，当使用TCPConnection中的Channel对象，
 * 调用其相关方法时，TcpConnection可能由于连接关闭提前执行析构，这种内存释放顺序是错误的，
 * 因此在 Channel 回调中检查tie_指向的TcpConnection是否还存在
 **/
void Channel::handleEvents() {
  loop_->assertInLoopThread();
  if (tied_) {
    auto guard =
        tie_.lock();  //返回与weak_prt关联的shared_ptr对象，如果对象已经被释放，返回空指针
    if (guard != nullptr) {
      handleEventWithGuard();
    }
  } else
    handleEventWithGuard();
}

int Channel::fd() const { return fd_; }
bool Channel::isNoneEvents() const { return events_ == 0; }
unsigned Channel::events() const { return events_; }
void Channel::setRevents(unsigned revents) { revents_ = revents; }
void Channel::tie(const std::shared_ptr<void>& rhs) {
  tie_ = rhs;
  tied_ = true;
}

//设置event update()注册或注销
void Channel::enableRead() {
  events_ |= (EPOLLIN | EPOLLPRI);
  update();
}
void Channel::enableWrite() {
  events_ |= EPOLLOUT;
  update();
}
void Channel::disableRead() {
  events_ &= ~EPOLLIN;
  update();
}
void Channel::disableWrite() {
  events_ &= ~EPOLLOUT;
  update();
}
void Channel::disableAll() {
  events_ = 0;
  update();
}

bool Channel::isReading() const { return events_ & EPOLLIN; }
bool Channel::isWriting() const { return events_ & EPOLLOUT; }

// 利用loop_对象的epollpoller进行注册或注销
void Channel::update() { loop_->updateChannel(this); }
void Channel::remove() {
  assert(this->pooling);
  loop_->removeChannel(this);
}

void Channel::handleEventWithGuard() {
  handlingEvents_ = true;
  // 调用前都要判断回调函数已注册
  if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) {
    if (closeCallback_) closeCallback_();
  }
  if (revents_ & EPOLLERR) {
    if (errorCallback_) errorCallback_();
  }
  if (revents_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP)) {
    if (readCallback_) readCallback_();
  }
  if (revents_ & EPOLLOUT) {
    if (writeCallback_) writeCallback_();
  }
  handlingEvents_ = false;
}