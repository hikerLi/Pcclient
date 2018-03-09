#ifndef COMMON_H
#define COMMON_H

#include<event.h>
#include<event2/bufferevent.h>
#include<event2/buffer.h>
#include<event2/util.h>

#include <string>
#include <cstring>
#include <crossplatform.h>
#include <vector>
#include <functional>

struct EndPort
{
    std::string ip;
    short port;
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
        return 0 == ePort1.ip.compare(ePort2.ip) && ePort1.port == ePort2.port;
    }
};


typedef int HANDLE_T;

#define MAX_PAYLOAD 4096

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
    std::string streamFilePath;
    EndPort ePort;
    std::vector<std::string> headerLines;
    std::vector<std::string> paylaodLines;
};




#endif // COMMON_H
