#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <common.h>

class ClientBase
{
public:
    ClientBase();

    virtual void Start(const EndPort& ePort) = 0;

    virtual bool SendMessage(const std::string& payload) = 0;
};

#endif // CLIENTBASE_H
