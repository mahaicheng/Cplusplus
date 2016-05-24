/*************************************************************************
	> 文件名: main.cc
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 16时22分08秒
 ************************************************************************/

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

