#include "udpclient.h"
#include <Common/common.h>
#include <functional>
#include <statics.h>

UdpClient::UdpClient(const PackageConfig &PkgConfig) : ClientBase(PkgConfig), bUseKCP(PkgConfig.bUseKcp)
{
    mConnMgr = new ConnectionManager();
    Statics::g_Timer.Add(10, [=](){
        mConnMgr->UpdateAllKcpTimer();
    });
}

UdpClient::~UdpClient()
{
    delete mConnMgr;
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
}

bool UdpClient::SendMessage(const std::__cxx11::string &payload)
{
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr) );

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(ePort.port);
    SETSERVERADDR(server_addr, ePort.ip);

    if(bUseKCP){
        return -1 != mConnMgr->PushToKcpSendQue(kcp, payload);
    }else{
        return -1 != ::sendto(sockfd, payload.c_str(), payload.size(), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    }
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

    std::string data;
    EndPort ePort;
    kcp_conv_t conv;
    std::string payload;
    if(bUseKCP && mConnMgr){
        mConnMgr->UdpRecvPackage(data, ePort);
        if(mConnMgr->HandleKcpPackage(data, ePort, conv, payload)){
            kcp = conv;
        }
    }else{

        struct sockaddr_in server_addr;
        uint32_t addr_size = sizeof(server_addr);
        char data[MAX_PAYLOAD];
        int32_t nNumberOfRead = ::recvfrom(sockfd, data, MAX_PAYLOAD, 0, (struct sockaddr*)&server_addr, &addr_size);
        if(-1 == nNumberOfRead){
            printf("recvfrom read 0!\n");
            return ;
        }

        std::string strMsg(data, nNumberOfRead);
        payload = strMsg;
    }
    emit(MessageSignal(ePort, payload));
}

void UdpClient::StaticMessageCB(const int sock, short which, void *arg)
{
    UdpClient* UClt = (UdpClient*)arg;
    UClt->MessageCB(sock, which, arg);
}

