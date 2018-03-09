#include "packagemanager.h"
#include <tcpclient.h>
#include <udpclient.h>
#include <threadpool.h>
PackageManager::PackageManager()
{

}

void PackageManager::Start()
{
//    event_set_log_callback();
    ThreadPoolIns.Start();
}

void PackageManager::SendPackage(const PackageConfig &pConfig)
{
    const EndPort& ePort = pConfig.ePort;
    ClientBase* client = nullptr;
    if(mConnectClt.find(ePort) == mConnectClt.end()){
        switch(pConfig.pType){
        case EMPROTOTYPE::TCP:{
            client = new TcpClient();
        }
            break;
        case EMPROTOTYPE::UDP:{
            client = new UdpClient();
        }
            break;
        }

        mConnectClt.insert(std::make_pair(ePort, client));

        const EndPort ThreadEndPort = ePort;
        ThreadPoolIns.Submit([=](){
            client->Start(ThreadEndPort);
        });
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }else{
        client = mConnectClt[ePort];
    }

    std::string payload = ProcessPackage(pConfig);

    client->SendMessage(payload);

}

std::__cxx11::string PackageManager::ProcessPackage(const PackageConfig &pConfig)
{
    std::string header, payload, retpayload;
    for(auto line : pConfig.headerLines){
        if(!line.empty()){
            header += line;
        }
    }


    for(auto line : pConfig.paylaodLines){
        if(!line.empty()){
            payload += line;
        }
    }

    //streamtype
    switch(pConfig.sType){
    case EMSTREAMTYPE::HEX:{
        std::string tmp = header + payload;
        uint8_t data = 0;
        uint8_t mul = 1;
        for(auto ch : tmp){
            if('-' != ch){
                uint8_t tdata = 0;
                if(ch >= '0' && ch <= '9'){
                    tdata += ch - '0';
                }else if(ch >= 'A' && ch <= 'Z'){
                    tdata += (ch - 'A') * 10;
                }else if(ch >= 'a' && ch <= 'z'){
                    tdata += (ch - 'a') * 10;
                }
                data *= mul;
                data += tdata;
                mul *= 16;
            }else{
                retpayload.push_back(data);
                data = 0;
                mul = 1;
            }
        }

    }
        break;
    case EMSTREAMTYPE::PROTOBUFFERS:{

    }
    case EMSTREAMTYPE::FLATBUFFERS:{

    }
    default:{
        retpayload = header + payload;
    }

    }

    return retpayload;
}

