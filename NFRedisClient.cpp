//
// Created by LUSHENG HUANG on 17/11/17.
//

#include "NFRedisClient.h"

NFRedisClient::NFRedisClient()
{
    m_pRedisClientSocket = new NFRedisClientSocket();
    m_pRedisResult = new NFRedisResult(m_pRedisClientSocket);
}


bool NFRedisClient::ConnectTo(const std::string &ip, const int port, const std::string &auth)
{
    m_pRedisClientSocket->Connect(ip, port);

    return false;
}

bool NFRedisClient::SelectDB(int dbnum)
{
    return false;
}

bool NFRedisClient::KeepLive()
{
    return false;
}

bool NFRedisClient::Execute()
{
    m_pRedisClientSocket->Execute();
    return false;
}

bool NFRedisClient::GetStatusReply()
{
    if (m_pRedisResult->ReadReply(NFREDIS_RESP_TYPE::NFREDIS_RESP_STATUS))
    {
        if (m_pRedisResult->GetResultType() == NFREDIS_RESULT_STATUS::NFREDIS_RESULT_STATUS_OK
                && m_pRedisResult->GetRespType() == NFREDIS_RESP_TYPE::NFREDIS_RESP_STATUS
                && m_pRedisResult->IsOKRespStatus())
        {
            return true;
        }
    }


    return false;
}

bool NFRedisClient::GetIntReply()
{
    return false;
}

bool NFRedisClient::GetBulkReply()
{
    if (m_pRedisResult->ReadReply(NFREDIS_RESP_TYPE::NFREDIS_RESP_BULK))
    {
        if (m_pRedisResult->GetResultType() == NFREDIS_RESULT_STATUS::NFREDIS_RESULT_STATUS_OK
            && m_pRedisResult->GetRespType() == NFREDIS_RESP_TYPE::NFREDIS_RESP_BULK)
        {
            return true;
        }
    }


    return false;
}

bool NFRedisClient::GetArrayReply()
{
    return false;

}

NFRedisResult *NFRedisClient::GetRedisResult()
{
    return m_pRedisResult;
}
