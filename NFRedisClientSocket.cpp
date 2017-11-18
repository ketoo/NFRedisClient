//
// Created by LUSHENG HUANG on 17/11/17.
//

#include "NFRedisClient.h"
#include "NFRedisClientSocket.h"

#ifdef WIN32
#include <WS2tcpip.h>
#include <winsock2.h>
#include <Windows.h>
#pragma comment(lib, "Ws2_32.lib")

int NFRedisClientSocket::Connect(const std::string &ip, const int port)
{
    return 0;
}

int NFRedisClientSocket::SetNoDelay()
{
    return 0;
}

int NFRedisClientSocket::Close()
{
    return 0;
}

int NFRedisClientSocket::Write(const char *buf, int count)
{
    return 0;
}

int NFRedisClientSocket::ReadN(char *buf, int count)
{
    return 0;
}

int NFRedisClientSocket::ReadLine(std::string &line)
{
    return 0;
}

int NFRedisClientSocket::ClearBuff()
{
    return 0;
}

#else
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

bool NFRedisClientSocket::Connect(const std::string &ip, const int port)
{
    fd = socket(AF_INET , SOCK_STREAM , 0);
    if (fd == -1)
    {
        printf("Could not create socket: %s\n", strerror(errno));
        return false;
    }

    struct sockaddr_in server;

    server.sin_addr.s_addr = inet_addr(ip.c_str());
    server.sin_family = AF_INET;
    server.sin_port = htons( port );

    //Connect to remote server
    if (connect(fd , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        perror("connect failed. Error");
        return false;
    }

    return true;
}

int NFRedisClientSocket::SetNoDelay()
{
    //int flags  = fcntl(fd,F_GETFL,0);
    //fcntl(fd,F_SETFL,flags&~O_NONBLOCK);
    int yes = 1;
    if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &yes, sizeof(yes)) == -1)
    {
        return -1;
    }

    int flags;
    if ((flags = fcntl(fd, F_GETFL)) == -1)
    {
        return -1;
    }
    if (fcntl(fd, F_SETFL, flags | O_NONBLOCK) == -1)
    {
        return -1;
    }
    return 0;
}

int NFRedisClientSocket::Close()
{
    return 0;
}

int NFRedisClientSocket::Write(const char *buf, int count)
{
    if( send(fd, buf, count, 0) < 0)
    {
        puts("Send failed");
        close(fd);

        return -1;
    }


    return 0;
}

bool NFRedisClientSocket::ReadN(char *buf, int count)
{
    while (count > mstrBuff.length())
    {
        Execute();
    }

    if (mstrBuff.length() >= count)
    {
        memcpy(buf, mstrBuff.data(), count);
        mstrBuff.erase(0, count);

        return true;
    }

    return false;
}

bool NFRedisClientSocket::ReadLine(std::string &line)
{
    line.clear();

    bool bFindLine = false;
    int len = -1;
    const char* p = mstrBuff.data();

    while (!bFindLine)
    {

        for (int i = 0; i < mstrBuff.length(); ++i)
        {
            p++;
            if (i < (mstrBuff.length() -1) && *p == '\r' && *(p+1) == '\n')
            {
                len = i;
                bFindLine = true;
                break;
            }
        }

        if (!bFindLine)
        {
            Execute();
        }
    }

    if (len < 0)
    {
        //yield

        return false;
    }

    int nTotalLen = len + 1 + NFREDIS_SIZEOF_CRLF;
    line.append(mstrBuff.data(), nTotalLen);
    mstrBuff.erase(0, nTotalLen);

    return true;
}

int NFRedisClientSocket::ClearBuff()
{
    return 0;
}

int NFRedisClientSocket::Execute()
{
    char buff[1024] = {0};

    int bufflen = ::recv(fd, buff, sizeof(buff), 0);
    if(bufflen < 0)
    {
        return 0;
    }

    mstrBuff.append(buff, bufflen);

    return 0;
}

void NFRedisClientSocket::AddBuff(const std::string &buff)
{
    mstrBuff.append(buff);
}

int NFRedisClientSocket::BuffLength()
{
    return mstrBuff.length();
}


#endif

