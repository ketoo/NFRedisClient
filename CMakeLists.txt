cmake_minimum_required(VERSION 3.8)
project(NFRedisPlugin)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp NFRedisClient.cpp NFRedisClient.h NFRedisResult.cpp NFRedisResult.h NFRedisCommand.cpp NFRedisCommand.h NFRedisClientKey.cpp NFRedisClientList.cpp NFRedisClientHash.cpp NFRedisClientString.cpp NFRedisClientSet.cpp NFRedisClientSort.cpp NFRedisClientGEO.cpp NFRedisClientServer.cpp NFRedisClientPubSub.cpp NFRedisProtocolDefine.h NFRedisClientSocket.cpp NFRedisClientSocket.h NFRedisTester.cpp NFRedisTester.h)
add_executable(NFRedisPlugin ${SOURCE_FILES})