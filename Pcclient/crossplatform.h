#ifndef CROSSPLATFORM_H
#define CROSSPLATFORM_H

#if define(Q_OS_WIN32)
#define SETSERVERADDR(server_addr, ip) \
    server_addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());



#else
#define SETSERVERADDR(server_addr, ip) \
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());


#endif


#endif // CROSSPLATFORM_H
