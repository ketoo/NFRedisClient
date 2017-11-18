//
// Created by LUSHENG HUANG on 17/11/17.
//

#ifndef NFREDISPLUGIN_NFREDISCLIENTSOCKET_H
#define NFREDISPLUGIN_NFREDISCLIENTSOCKET_H


#include <string>

class NFRedisClientSocket
{
public:

    bool Connect(const std::string& ip, const int port);
    int SetNoDelay();
    int Close();
    int Write(const char *buf, int count);

    bool ReadN(char *buf, int count);
    bool ReadLine(std::string& line);

    int ClearBuff();
    int BuffLength();
    int Execute();

    /////test
    void AddBuff(const std::string& buff);

private:
    int64_t fd;
    std::string mstrBuff;
};


#endif //NFREDISPLUGIN_NFREDISCLIENTSOCKET_H
