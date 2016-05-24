#include"EchoServerImpl.h"
#include<functional>

using namespace std::placeholders;
using namespace muduo;
using namespace muduo::net;

EchoServerImpl::EchoServerImpl(EventLoop *loop, const InetAddress &listenAddr, \
				const string &name) : 
	server_(loop, listenAddr, name), sendClientContent_(false)
{
	server_.setConnectionCallback(bind(&EchoServerImpl::onConnection, this, _1));
	server_.setMessageCallback(bind(&EchoServerImpl::onMessage, this, _1, _2, _3));
	server_.setWriteCompleteCallback(bind(&EchoServerImpl::onWriteComplete, this, _1));
}

void EchoServerImpl::start()
{
	server_.start();
}
    
void EchoServerImpl::onConnection(const TcpConnectionPtr &conn)
{
    if (conn->connected())
    {
        conn->send("Welcome to MHC Echo Server!\nEnter \"exit\" to exit...\n");
    }
}

void EchoServerImpl::onMessage(const TcpConnectionPtr &conn, \
								Buffer *buf, Timestamp time)
{
    muduo::string msg(buf->retrieveAllAsString());
	if (msg.find("exit") != std::string::npos && msg.size() == 6)
	{
			conn->forceClose();
	}
	sendClientContent_ = true;
    conn->send(msg);
}

void EchoServerImpl::onWriteComplete(const TcpConnectionPtr &conn)
{
	if (sendClientContent_)
	{
		sendClientContent_ = false;
		conn->send("\nPlease enter more ...\n");
	}
}