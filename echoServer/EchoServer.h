/*************************************************************************
	> 文件名: EchoServer.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 15时48分09秒
 ************************************************************************/

#ifndef _ECHOSERVER_H_
#define _ECHOSERVER_H_

#include<memory> 	// for shared_ptr
#include"EchoServerImpl.h" 	// declaration of class EchoServerImpl
#include<muduo/net/EventLoop.h>
#include<muduo/net/InetAddress.h>

class EchoServer 
{
public:
    EchoServer(muduo::net::EventLoop *loop, \
				const muduo::net::InetAddress &listenAddr, \
				const muduo::string &name);
    // noncopyable
	EchoServer(const EchoServer &) = delete;
    EchoServer & operator=(const EchoServer &) = delete;

    void start();
private:
    std::shared_ptr<EchoServerImpl> impl;
};

#endif
