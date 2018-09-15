#ifndef _ECHOSERVERIMPL_H_
#define _ECHOSERVERIMPL_H_

#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpServer.h>

class EchoServerImpl
{
  public:
    EchoServerImpl(muduo::net::EventLoop *, const muduo::net::InetAddress &,
                   const muduo::string &);
    // noncopyable
    EchoServerImpl(const EchoServerImpl &) = delete;
    EchoServerImpl &operator=(const EchoServerImpl &) = delete;

    void start();

  protected:
    void onConnection(const muduo::net::TcpConnectionPtr &conn);
    void onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf,
                   muduo::Timestamp time);
    void onWriteComplete(const muduo::net::TcpConnectionPtr &conn);

  private:
    muduo::net::TcpServer server_;
    bool sendClientContent_;
};

#endif