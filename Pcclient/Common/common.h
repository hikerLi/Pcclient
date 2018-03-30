#ifndef COMMON_H
#define COMMON_H

#include<event.h>
#include<event2/bufferevent.h>
#include<event2/buffer.h>
#include<event2/util.h>

#include <string>
#include <cstring>
#include <Common/crossplatform.h>
#include <vector>
#include <functional>

#ifdef _WIN32
    #include <winsock2.h>
    #include <time.h>
    #include <Winsock2.h>
#else
    #include <sys/time.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <sys/unistd.h>
    #include <netinet/in.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <arpa/inet.h>
#endif

struct EndPort
{
    std::string ip;
    short port;

    bool Empty() const{
        return (ip.empty() || 0 == port);
    }
};

struct EndPort_hash {
 std::size_t operator() (const EndPort& ePort) const {
  std::hash<std::string> hash_function;
  std::string key = ePort.ip + std::to_string(ePort.port);
  std::size_t returnValue = hash_function(key);

  return returnValue;
 }
};

struct EndPort_Eq
{
    bool operator()(const EndPort& ePort1, const EndPort& ePort2) const{
        return (0 == ePort1.ip.compare(ePort2.ip)) && ePort1.port == ePort2.port;
    }
};


typedef int HANDLE_T;

#define MAX_PAYLOAD 8192
#define MAXPAYLOAD MAX_PAYLOAD

#define LOG_DEBUG printf
#define LOG_ERR printf

enum EMSTREAMTYPE
{
    NONE = 0,
    HEX,
    PROTOBUFFERS,
    FLATBUFFERS,
};

enum EMTIMERTYPE
{
    NOTIMER = 0,
    SECONDS_5,
    SECONDS_10,
    SECONDS_30,
    MINUTE_1,
    MINUTE_15,
};

enum EMPROTOTYPE
{
    TCP = 0,
    UDP,
};

struct PackageConfig
{
    EMSTREAMTYPE sType;
    EMPROTOTYPE pType;
    EMTIMERTYPE tType;
    uint32_t maxBuffSize;
    std::string streamFilePath;
    EndPort ePort;
    std::vector<std::string> headerLines;
    std::vector<std::string> paylaodLines;

    bool bUseKcp;
};


//获取当前时间毫秒数
uint64_t GetCurrentTimeMsec();

#endif // COMMON_H
