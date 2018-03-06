#include "tcpclient.h"
#include <crossplatform.h>

TcpClient::TcpClient()
{

}

void TcpClient::Start(const EndPort &ePort)
{
    struct event_base *base = event_base_new();

    bev = bufferevent_socket_new(base, -1,
                                                     BEV_OPT_CLOSE_ON_FREE);
    //监听终端输入事件
    struct event* ev_cmd = event_new(base, STDIN_FILENO,
                                     EV_READ | EV_PERSIST,
                                     cmd_msg_cb, (void*)bev);

    event_add(ev_cmd, NULL);

    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr) );

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ePort.port);

    SETSERVERADDR(server_addr, ePort.ip);

    bufferevent_socket_connect(bev, (struct sockaddr *)&server_addr,
                               sizeof(server_addr));

    bufferevent_setcb(bev, server_msg_cb, NULL, event_cb, (void*)ev_cmd);
    bufferevent_enable(bev, EV_READ | EV_PERSIST);

    event_base_dispatch(base);

    printf("finished \n");
}

bool TcpClient::SendMessage(const std::__cxx11::string &payload)
{
    return 0 == bufferevent_write(bev, payload.c_str(), payload.size());
}

void TcpClient::MessageCB(bufferevent *bev, void *arg)
{
    char msg[4096];

    size_t len = bufferevent_read(bev, msg, sizeof(msg));
    msg[len] = '\0';

    printf("recv %s from server\n", msg);
}

void TcpClient::EventCB(bufferevent *bev, short event, void *arg)
{
    if (event & BEV_EVENT_EOF)
        printf("connection closed\n");
    else if (event & BEV_EVENT_ERROR)
        printf("some other error\n");
    else if( event & BEV_EVENT_CONNECTED)
    {
        printf("the client has connected to server\n");
        return ;
    }

    //这将自动close套接字和free读写缓冲区
    bufferevent_free(bev);

    struct event *ev = (struct event*)arg;
    event_free(ev);
}