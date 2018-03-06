#ifndef COMMON_H
#define COMMON_H

#include<event.h>
#include<event2/bufferevent.h>
#include<event2/buffer.h>
#include<event2/util.h>

#include <string>

struct EndPort
{
    std::string ip;
    short port;
};

typedef int HANDLE_T;

#endif // COMMON_H
