//
// Created by LUSHENG HUANG on 17/11/17.
//
#include "NFRedisClient.h"

NFRedisResult* NFRedisClient::DEL(const std::string &key)
{
    return m_pRedisResult;
}

NFRedisResult* NFRedisClient::DEL(const std::vector<std::string> &keys)
{
    return m_pRedisResult;
}

NFRedisResult* NFRedisClient::DUMP(const std::string &key, std::string &out)
{
    return m_pRedisResult;
}

NFRedisResult* NFRedisClient::EXISTS(const std::string &key)
{
    return m_pRedisResult;
}