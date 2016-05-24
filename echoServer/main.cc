#include"EchoServer.h"
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>

using namespace muduo::net;

int main()
{
    EventLoop loop;
    InetAddress listenAddr(2016);
    EchoServer server(&loop, listenAddr, "MHC Echo Server");
    server.start();
    loop.loop();
}

