/*************************************************************************
	> 文件名: EchoServer.cc
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 15时55分39秒
 ************************************************************************/

#include"EchoServer.h"
#include"Impl.h"

#include<utility>
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>
#include<muduo/net/TcpServer.h>

using namespace muduo;
using namespace muduo::net;
using namespace std;
using namespace placeholders;



EchoServer::EchoServer(EventLoop *loop, const InetAddress &listenAddr, const muduo::string &name):
		impl(make_shared<Impl>(loop, listenAddr, name))
{ 
	
}

void EchoServer::start()
{
    impl->start();
}
