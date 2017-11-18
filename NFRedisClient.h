//
// Created by LUSHENG HUANG on 17/11/17.
//

#ifndef NFREDISPLUGIN_NFREDISCLIENT_H
#define NFREDISPLUGIN_NFREDISCLIENT_H


#include <string>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdexcept>
#include <ctime>
#include <sstream>
#include <iostream>
#include <random>

#include "NFRedisResult.h"
#include "NFRedisCommand.h"

typedef std::string string_type;
typedef std::vector<string_type> string_vector;
typedef std::pair<string_type, string_type> string_pair;
typedef std::vector<string_pair> string_pair_vector;
typedef std::pair<string_type, double> string_score_pair;
typedef std::vector<string_score_pair> string_score_vector;
typedef std::set<string_type> string_set;

class NFRedisClient
{
public:
    NFRedisClient();

    bool ConnectTo(const std::string& ip, const int port, const std::string& auth);

    bool SelectDB(int dbnum);

    bool KeepLive();

    bool Execute();

    NFRedisResult* GetRedisResult();
    /////////client key//////////////

    NFRedisResult* DEL(const std::string& key);
    NFRedisResult* DEL(const std::vector<std::string>& keys);

    NFRedisResult* DUMP(const std::string& key, std::string& out);

    NFRedisResult* EXISTS(const std::string& key);


    /////////client String//////////////

    NFRedisResult* APPEND(const std::string& key, const std::string& value);
    //NFRedisResult* BITCOUNT
    //NFRedisResult* BITOP
    //NFRedisResult* BITFIELD(const std::string& key);
    NFRedisResult* DECR(const std::string& key);
    NFRedisResult* DECRBY(const std::string& key, const int64_t v);
    NFRedisResult* GET(const std::string& key);
    //NFRedisResult* GETBIT(const std::string& key);
    //NFRedisResult* GETRANGE(const std::string& key);

    NFRedisResult* GETSET(const std::string& key, const std::string& value);
    NFRedisResult* INCR(const std::string& key);
    NFRedisResult* INCRBY(const std::string& key, const int64_t v);
    NFRedisResult* INCRBYFLOAT(const std::string& key, const float fv);

    NFRedisResult* MGET(const string_vector& keys, string_vector& values);
    NFRedisResult* MSET(const string_pair_vector& values);

    //NFRedisResult* MSETNX(const std::string& key);
    //NFRedisResult* PSETEX(const std::string& key);

    NFRedisResult* SET(const std::string& key, const std::string& value);

    //NFRedisResult* SETBIT(const std::string& key);
    NFRedisResult* SETEX(const std::string& key, const std::string& value, int time);
    NFRedisResult* SETNX(const std::string& key, const std::string& value);
    //NFRedisResult* SETRANGE(const std::string& key);
    NFRedisResult* STRLEN(const std::string& key);


    /////////client server//////////////
    NFRedisResult* FLUSHALL();
    NFRedisResult* FLUSHDB();

private:


    bool GetReply();

    bool GetStatusReply();
    bool GetIntReply();
    bool GetBulkReply();
    bool GetArrayReply();


private:
    NFRedisClientSocket* m_pRedisClientSocket;
    NFRedisResult* m_pRedisResult;
};


#endif //NFREDISPLUGIN_NFREDISCLIENT_H
