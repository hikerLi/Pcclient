#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <Client/clientbase.h>


class TcpClient : public ClientBase
{
public:
    TcpClient(const PackageConfig &PkgConfig);

    virtual void Start(const EndPort& ePort);

    virtual bool SendMessage(const std::string& payload);

protected:
    void MessageCB(struct bufferevent* bev, void* arg);

    void EventCB(struct bufferevent *bev, short event, void *arg);

    void WriteCB(struct bufferevent *bev, short event, void *arg);


    static void StaticMessageCB(struct bufferevent* bev, void* arg);

    static void StaticEventCB(struct bufferevent *bev, short event, void *arg);

    static void StaticWriteCB(struct bufferevent *bev, short event, void *arg);


private:
    struct bufferevent* bev;
};

#endif // TCPCLIENT_H
