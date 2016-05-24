/*************************************************************************
	> 文件名: EchoServer.h
	> 作者: 马海城
	> 邮箱: hchma@outlook.com
	> 创建日期: 2016年05月24日 星期二 15时48分09秒
 ************************************************************************/

#ifndef _ECHOSERVER_H_
#define _ECHOSERVER_H_

#include<memory>
#include<muduo/base/Types.h>
#include<muduo/net/TcpServer.h>
#include<muduo/net/InetAddress.h>
#include<muduo/net/EventLoop.h>
#include"Impl.h"

class EchoServer 
{
public:
    EchoServer(muduo::net::EventLoop *, const muduo::net::InetAddress &, const muduo::string &);
    EchoServer(const EchoServer &) = delete;
    EchoServer & operator=(const EchoServer &) = delete;

    void start();
private:
    std::shared_ptr<Impl> impl;
};

#endif
