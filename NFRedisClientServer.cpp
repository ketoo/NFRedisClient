//
// Created by LUSHENG HUANG on 17/11/17.
//

#include "NFRedisClient.h"

NFRedisResult *NFRedisClient::FLUSHALL()
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("FLUSHALL");

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::FLUSHDB()
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("FLUSHDB");

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

    GetStatusReply();


    return m_pRedisResult;
}
