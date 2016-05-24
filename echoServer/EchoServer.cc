/*************************************************************************
	> 文件名: EchoServer.cc
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 15时55分39秒
 ************************************************************************/

#include"EchoServer.h"

using namespace muduo::net;

EchoServer::EchoServer(muduo::net::EventLoop *loop, const muduo::net::InetAddress &listenAddr, const muduo::string &name):
		impl(std::make_shared<EchoServerImpl>(loop, listenAddr, name))
{ 
	
}

void EchoServer::start()
{
    impl->start();
}
