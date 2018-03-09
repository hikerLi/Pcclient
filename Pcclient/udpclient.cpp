#include "udpclient.h"
#include <common.h>
#include <functional>

UdpClient::UdpClient()
{

}

void UdpClient::Start(const EndPort &ePort)
{
    sockfd = UdpInit();
    if( sockfd == -1)
    {
        perror("udp_connect error ");
        return;
    }

    this->ePort = ePort;

    printf("connect to server successful\n");

    struct event_base *base = event_base_new();

    struct event *udp_event = event_new(base, sockfd, EV_READ|EV_PERSIST, UdpClient::StaticMessageCB, this);

    event_add(udp_event, NULL);

    event_dispatch();

    printf("finished \n");
    return ;
}

bool UdpClient::SendMessage(const std::__cxx11::string &payload)
{
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr) );

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ePort.port);
    SETSERVERADDR(server_addr, ePort.ip);

    return -1 != ::sendto(sockfd, payload.c_str(), payload.size(), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
}

HANDLE_T UdpClient::UdpInit()
{
    HANDLE_T sockfd;

    sockfd = ::socket(PF_INET, SOCK_DGRAM, 0);
    if( sockfd == -1 )
        return sockfd;

    evutil_make_socket_nonblocking(sockfd);

    return sockfd;
}

void UdpClient::MessageCB(const int sock, short int which, void *arg)
{
    struct sockaddr_in server_addr;
    uint32_t addr_size = sizeof(server_addr);
    char data[MAX_PAYLOAD];
    int32_t nNumberOfRead = ::recvfrom(sockfd, data, MAX_PAYLOAD, 0, (struct sockaddr*)&server_addr, &addr_size);
    if(-1 == nNumberOfRead){

    }
}

void UdpClient::StaticMessageCB(const int sock, short which, void *arg)
{
    UdpClient* UClt = (UdpClient*)arg;
    UClt->MessageCB(sock, which, arg);
}

