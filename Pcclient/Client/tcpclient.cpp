#include "tcpclient.h"
#include <Common/crossplatform.h>
#include <Common/common.h>

TcpClient::TcpClient(const PackageConfig &PkgConfig) : ClientBase(PkgConfig)
{

}

void TcpClient::Start(const EndPort &ePort)
{
    struct event_base *base = event_base_new();

    evutil_socket_t fd = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    emit(EventSignal(QString("connection start:%1").arg(fd)));

    bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr) );

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ePort.port);

    SETSERVERADDR(server_addr, ePort.ip);
    this->ePort = ePort;

    bConnect = 0 == bufferevent_socket_connect(bev, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(bConnect){
        bufferevent_setcb(bev, &TcpClient::StaticMessageCB, nullptr, &TcpClient::StaticEventCB, this);
        bufferevent_enable(bev, EV_READ | EV_PERSIST);

        event_base_dispatch(base);

        printf("finished \n");
    }
}

bool TcpClient::SendMessage(const std::string &payload)
{
    if(nullptr == bev)
        return false;
    int32_t ret = bufferevent_write(bev, payload.c_str(), payload.size());
    return 0 == ret;
}

void TcpClient::MessageCB(bufferevent *bev, void *arg)
{
    char msg[MAX_PAYLOAD];

    size_t len = bufferevent_read(bev, msg, sizeof(msg));
    msg[len] = '\0';

    std::string strMsg(msg, len);

    emit(MessageSignal(ePort, strMsg));

    printf("recv %s from server\n", msg);
}

void TcpClient::EventCB(bufferevent *bev, short event, void *arg)
{
    if (event & BEV_EVENT_EOF){
        emit(EventSignal("connection closed"));
        emit(CloseConnectSignal(ePort));
        event_loopbreak();
    }
    else if (event & BEV_EVENT_ERROR)
        emit(EventSignal("some other error"));
    else if( event & BEV_EVENT_CONNECTED){
        emit(EventSignal("the client has connected to server"));
        return ;
    }else{
        emit(EventSignal(QString("what event %1").arg(event)));
    }
    //这将自动close套接字和free读写缓冲区
    bufferevent_free(bev);
}

void TcpClient::WriteCB(bufferevent *bev, short event, void *arg)
{

}

void TcpClient::StaticMessageCB(bufferevent *bev, void *arg)
{
    TcpClient* TcpClt = (TcpClient*)arg;
    TcpClt->MessageCB(bev, arg);
}

void TcpClient::StaticEventCB(bufferevent *bev, short event, void *arg)
{
    TcpClient* TcpClt = (TcpClient*)arg;
    TcpClt->EventCB(bev, event, arg);
}

void TcpClient::StaticWriteCB(bufferevent *bev, short event, void *arg)
{
    TcpClient* TcpClt = (TcpClient*)arg;
    TcpClt->WriteCB(bev, event, arg);
}
