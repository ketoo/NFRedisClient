//
// Created by LUSHENG HUANG on 17/11/17.
//

#include "NFRedisClient.h"



NFRedisResult *NFRedisClient::APPEND(const std::string &key, const std::string &value)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::DECR(const std::string &key)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::DECRBY(const std::string &key, const int64_t v)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::GETSET(const std::string &key, const std::string &value)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::INCR(const std::string &key)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::INCRBY(const std::string &key, const int64_t v)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::INCRBYFLOAT(const std::string &key, const float fv)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::MGET(const string_vector &keys, string_vector &values)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("MGET");

    for (int i = 0; i < keys.size(); ++i)
    {
        cmd << keys[i];
    }

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        //mxRedisResult
        return m_pRedisResult;
    }

    GetBulkReply();

    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::MSET(const string_pair_vector &values)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("MSET");

    for (int i = 0; i < values.size(); ++i)
    {
        cmd << values[i].first;
        cmd << values[i].second;
    }

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        //mxRedisResult
        return m_pRedisResult;
    }

    GetStatusReply();

    return m_pRedisResult;
}

NFRedisResult *NFRedisClient::SETEX(const std::string &key, const std::string &value, int time)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::SETNX(const std::string &key, const std::string &value)
{
    return nullptr;
}

NFRedisResult *NFRedisClient::STRLEN(const std::string &key)
{
    return nullptr;
}


NFRedisResult* NFRedisClient::SET(const std::string &key, const std::string &value)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("SET");
    cmd << key;
    cmd << value;

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        return m_pRedisResult;
    }

     GetStatusReply();


    return m_pRedisResult;
}

NFRedisResult* NFRedisClient::GET(const std::string &key)
{
    m_pRedisResult->Reset();

    NFRedisCommand cmd("GET");
    cmd << key;

    std::string msg = cmd.Serialize();

    int nRet = m_pRedisClientSocket->Write(msg.data(), msg.length());
    if (nRet != 0)
    {
        //mxRedisResult
        return m_pRedisResult;
    }

    GetBulkReply();

    return m_pRedisResult;
}