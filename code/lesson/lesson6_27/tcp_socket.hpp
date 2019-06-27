#pragma once
#include<cstdio>
#include<cstring>
#include<string>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>


class TcpSocket{
public:
    TcpSocket()
        :fd_(-1)
    {

    }

    bool Socket(){
        //AF_INET IPV4
        //SOCK_STREM 面向字节流
        fd_=socket(AF_INET,SOCK_STREAM,0);
        if(fd_<0){
            perror("socket");
            return false;
        }
        return true;
    }
    //给服务器使用
    bool


private:
     int fd_;
};
