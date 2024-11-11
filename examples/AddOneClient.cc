#include <iostream>
#include <thread>
#include "TcpClient.hpp"
#include "Logger.hpp"
#include "TcpConnection.hpp"
#include "EventLoop.hpp"

using namespace goa::ev;

class UserInput : noncopyable {

public:
    UserInput(const TcpConnectionPtr& conn) : conn_(conn) {
        conn_->setMessageCallback(std::bind(&UserInput::onMessage, this, std::placeholders::_1, std::placeholders::_2));
    }


    // 在tcpconnection::handleread中  收到信息时会调用  此处仅仅打印收到的信息
    void onMessage(const TcpConnectionPtr& conn, Buffer& buffer) {
        std::cout << buffer.retrieveAllAsString() << std::endl;
    }

    //额外的线程  持续从shell获取信息并发送
    void run() {
        std::string line;
        while (std::getline(std::cin, line)) {
            conn_->send(line);
        }
        conn_->shutdown();
    }

private:
    TcpConnectionPtr conn_;
};

class AddOneBench : noncopyable {

public:
    AddOneBench(EventLoop* loop, const InetAddress& addr) : loop_(loop), client_(loop, addr) {
           // 连接成功时 额外的回调  
        client_.setConnectionCallback(std::bind(&AddOneBench::onConnection, this, std::placeholders::_1));
    }              

    void start() {
        client_.start();       //尝试连接   失败会每隔3s重复请求
    }

    // 建立连接后 TcpClient::newConnection会调用该函数
    void onConnection(const TcpConnectionPtr& conn) {
        INFO("connection {} is [{}]", conn->name(), conn->connected() ? "up" : "down");

        // 额外的线程   用于发送信息   并利用userinput设置TcpConnection::messageCallback 
        if (conn->connected()) {
            auto th = std::thread([conn](){
                UserInput user(conn);
                user.run();
            });
            th.detach();
        }
        else {
            loop_->quit();
        }
    }
private:
    EventLoop* loop_;
    TcpClient client_;      // 含有connectorPtr
};

int main() {
    setLogLevel(LOG_LEVEL::LOG_LEVEL_WARN);
    EventLoop loop;
    InetAddress addr("127.0.0.1", 9877);
    AddOneBench client(&loop, addr);
    client.start();
    loop.loop();         // loop监听服务端的回复    并打印信息
}