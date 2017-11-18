#include <iostream>
#include <sstream>
#include "NFRedisClient.h"
#include "NFRedisTester.h"


int main()
{
    NFRedisTester xRedisTester;
    xRedisTester.RunTester();

    while (1)
    {

        xRedisTester.Execute();
    }

    return 0;

/*
    NFRedisResult xRedisResult(nullptr);

    xRedisResult.DeSerialize("+OK");
    std::cout << xRedisResult.GetRespString() << std::endl;

    xRedisResult.DeSerialize("-ERR unknown command 'foobar'");
    std::cout << xRedisResult.GetRespString() << std::endl;


    xRedisResult.DeSerialize(":1000\r\n");
    std::cout << xRedisResult.GetRespInt() << std::endl;

    xRedisResult.DeSerialize("$6\r\nfoobar\r\n");
    std::cout << xRedisResult.GetRespString() << std::endl;

    xRedisResult.DeSerialize("*4\r\n$3\r\nfoo\r\n$3\r\nbar\r\n$5\r\nHello\r\n$5\r\nWorld\r\n");
    std::vector<NFRedisResult> xRedisResultList1 = xRedisResult.GetRespArray();
    for (int i = 0; i < xRedisResultList1.size(); ++i)
    {
        std::cout << xRedisResultList1[i].GetRespString() << std::endl;
    }

    xRedisResult.ReadReply("*7\r\n:1\r\n:2\r\n$5\r\nWorld\r\n:3\r\n$5\r\nHello\r\n:4\r\n$6\r\nfoobar\r\n");
    std::vector<NFRedisResult> xRedisResultList2 = xRedisResult.GetRespArray();
    for (int i = 0; i < xRedisResultList2.size(); ++i)
    {
        std::cout << xRedisResultList2[i].GetRespString() << std::endl;
    }
    */
    return 0;
}