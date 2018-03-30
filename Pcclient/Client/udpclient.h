#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <Client/clientbase.h>
#include <Common/crossplatform.h>
#include <KCP/connectionmanager.h>

class UdpClient : public ClientBase
{
public:
    UdpClient(const PackageConfig &PkgConfig);
    ~UdpClient();

    void Start(const EndPort& ePort);

    bool SendMessage(const std::string& payload);
protected:
    HANDLE_T UdpInit();

    void MessageCB(const int sock, short int which, void *arg);

    static void StaticMessageCB(const int sock, short int which, void *arg);
private:
    HANDLE_T sockfd;

    bool bUseKCP;

    ConnectionManager* mConnMgr;

    kcp_conv_t kcp;
};

#endif // UDPCLIENT_H
