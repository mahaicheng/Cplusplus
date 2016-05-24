#include"EchoServer.h"

using namespace muduo::net;

EchoServer::EchoServer(muduo::net::EventLoop *loop, \
					const muduo::net::InetAddress &listenAddr, \
					const muduo::string &name):
		impl(std::make_shared<EchoServerImpl>(loop, listenAddr, name))
{ 
	
}

void EchoServer::start()
{
    impl->start();
}
