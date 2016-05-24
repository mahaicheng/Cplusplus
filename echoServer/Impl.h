#ifndef IMPL_H_
#define IMPL_H_

#include<utility>
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>
#include<muduo/net/TcpServer.h>

using namespace muduo;
using namespace muduo::net;
using namespace std;
using namespace placeholders;

class Impl 
{
public:
    Impl(EventLoop *loop, const InetAddress &listenAddr, const muduo::string &name) : 
        server_(loop, listenAddr, name), sendClientContent_(false)
    {
        server_.setConnectionCallback(bind(&Impl::onConnection, this, _1));
        server_.setMessageCallback(bind(&Impl::onMessage, this, _1, _2, _3));
        server_.setWriteCompleteCallback(bind(&Impl::onWriteComplete, this, _1));
    }
    void start()
    {
        server_.start();
    }
    
private:
    void onConnection(const TcpConnectionPtr &conn)
    {
        if (conn->connected())
        {
            conn->send("Welcome to MHC Echo Server!\nEnter \"exit\" to exit...\n");
        }
    }
    void onMessage(const TcpConnectionPtr &conn, Buffer *buf, Timestamp time)
    {
        muduo::string msg(buf->retrieveAllAsString());
		if (msg.find("exit") != std::string::npos && msg.size() == 6)
		{
				conn->forceClose();
		}
		sendClientContent_ = true;
        conn->send(msg);
		
    }
    void onWriteComplete(const TcpConnectionPtr &conn)
    {
		if (sendClientContent_)
		{
			sendClientContent_ = false;
			conn->send("\nPlease enter more ...\n");
		}
    }

private:
    TcpServer server_;
	bool sendClientContent_;
};

#endif