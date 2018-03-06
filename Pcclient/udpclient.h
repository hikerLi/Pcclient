#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <clientbase.h>
#include <crossplatform.h>

class UdpClient : public ClientBase
{
public:
    UdpClient();

    void Start(const EndPort& ePort);

    bool SendMessage(const std::string& payload);
protected:
    HANDLE_T UdpInit();

    void MessageCB(const int sock, short int which, void *arg);

private:
    HANDLE_T sockfd;
    EndPort ePort;
};

#endif // UDPCLIENT_H
