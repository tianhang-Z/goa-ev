#include "Acceptor.hpp"

#include "EventLoop.hpp"
#include "Logger.hpp"

using namespace goa::ev;

namespace {
int createSocket() {
  int ret = ::socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK | SOCK_CLOEXEC, 0);
  if (ret == -1) SYSFATAL("Acceptor createSocket");
  return ret;
}

}  // anonymous namespace

Acceptor::Acceptor(EventLoop* loop, const InetAddress& local)
    : listening_(false),
      loop_(loop),
      acceptfd_(createSocket()),
      acceptChannel_(loop, acceptfd_),
      local_(local) {
  int on = 1;
  //允许重用地址  服务器重启时不需要等待端口释放
  int ret = setsockopt(acceptfd_, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
  if (ret == -1) {
    SYSFATAL("Acceptor setsockopt SO_REUSEADDR");
  }
  // 许多个进程或线程绑定到同一个端口，并且系统会负载均衡地将连接分配给这些进程/线程。
  ret = setsockopt(acceptfd_, SOL_SOCKET, SO_REUSEPORT, &on, sizeof(on));
  if (ret == -1) {
    SYSFATAL("Acceptor setsockopt SO_REUSEPORT");
  }
  ret = bind(acceptfd_, local.getSockaddr(), local.getSocklen());
  if (ret == -1) {
    SYSFATAL("Acceptor bind");
  }
}

Acceptor::~Acceptor() { close(acceptfd_); }

bool Acceptor::listening() const { return listening_; }

void Acceptor::listen() {
  loop_->assertInLoopThread();
  int ret = ::listen(acceptfd_, SOMAXCONN);
  if (ret == -1) {
    SYSFATAL("Acceptor listen fatal");
  }
  acceptChannel_.setReadCallback(
      [this]() { handleRead(); });  // 当有连接请求到来时，交由handleRead处理
  acceptChannel_.enableRead();  // 将acceptfd_注册到epoll中
}

void Acceptor::setNewConnectionCallback(const NewConnectionCallback& callback) {
  newConnectionCallback_ = callback;
}

void Acceptor::handleRead() {
  loop_->assertInLoopThread();

  struct sockaddr_in addr;
  socklen_t len = sizeof(addr);

  int sockfd = ::accept4(acceptfd_, reinterpret_cast<sockaddr*>(&addr), &len,
                         SOCK_NONBLOCK | SOCK_CLOEXEC);
  if (sockfd == -1) {
    int savedErrno = errno;
    SYSERR("Acceptor accept4()");
    switch (savedErrno) {
      case ECONNABORTED:              // connection aborted
      case EMFILE:                    // 文件描述符用完了
        ERROR(strerror(savedErrno));  // log输出两种错误类型
        break;
      default:
        FATAL("unexpected accept4() error");
    }
  }

  if (newConnectionCallback_) {
    InetAddress peer;
    peer.setAddress(addr);
    newConnectionCallback_(sockfd, local_, peer);
  } else
    ::close(sockfd);
}
