#include "pkghandler.h"
#include <functional>
#include <Common/threadpool.h>
#include <Client/tcpclient.h>
#include <Client/udpclient.h>
#include <Common/timer.h>
#include <Stream/streamhex.h>
#include <statics.h>

uint64_t TimeArr[] = {5, 10, 30, 1 * 60, 15 * 60};

PkgHandler::PkgHandler()
{
    ThreadPoolIns.Start();
    //tcp hex
    Add(EMPROTOTYPE::TCP, EMSTREAMTYPE::HEX, this, &PkgHandler::TcpHexHandle);
    //recv
    AddRecv(EMPROTOTYPE::TCP, EMSTREAMTYPE::HEX, this, &PkgHandler::TcpHexRecvHandle);

    //udp
    Add(EMPROTOTYPE::UDP, EMSTREAMTYPE::NONE, this, &PkgHandler::UdpHandle);
}

void PkgHandler::Execute(const PackageConfig &PkgConfig)
{
    uint32_t ProtoType = PkgConfig.pType;
    uint32_t StreamType = PkgConfig.sType;
    handlers[ProtoType][StreamType](PkgConfig);
}

void PkgHandler::ExecuteRecv(ClientBase *clt, const std::__cxx11::string &payload)
{
    recvhandlers[clt->GetPType()][clt->GetSType()](clt, payload);
}

template<class TargetType, class FuncType>
void PkgHandler::Add(uint32_t ProtoType, uint32_t StreamType, TargetType *target, FuncType &&func)
{
    handlers[ProtoType][StreamType] = std::bind(std::forward<FuncType>(func), target, std::placeholders::_1);
}

template<class TargetType, class FuncType>
void PkgHandler::AddRecv(EMPROTOTYPE pType, EMSTREAMTYPE sType, TargetType *target, FuncType &&func)
{
    recvhandlers[pType][sType] = std::bind(std::forward<FuncType>(func), target, std::placeholders::_1, std::placeholders::_2);
}


ClientBase *PkgHandler::GetOrCreateClt(const PackageConfig &PkgConfig)
{
    ClientBase* client = nullptr;
    const EndPort ePort = PkgConfig.ePort;
    if(mConnectClt.find(ePort) != mConnectClt.end()){
        client = mConnectClt[ePort];
    }else{
        if(EMPROTOTYPE::TCP == PkgConfig.pType){
            client = new TcpClient(PkgConfig);
        }else{
            client = new UdpClient(PkgConfig);
        }

        connect(client, SIGNAL(EventSignal(QString)), this, SLOT(EventLogSlot(QString)));
        connect(client, SIGNAL(CloseConnectSignal(EndPort)), this, SLOT(CloseConnectSlot(EndPort)));
        connect(client, SIGNAL(MessageSignal(EndPort, std::string)), this, SLOT(EventMessageSlot(EndPort, std::string)));

        mConnectClt.insert(std::make_pair(ePort, client));

        ThreadPoolIns.Submit([=](){
            client->Start(ePort);
        });
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    if(!client->IsConnect()){
        delete mConnectClt[ePort];
        mConnectClt.erase(ePort);
        emit(EventLogSignal("connect failed."));
        return nullptr;
    }

    return client;
}

//tcp hex sender
void PkgHandler::TcpHexHandle(const PackageConfig &PkgConfig)
{
    ClientBase* client = GetOrCreateClt(PkgConfig);
    if(!client)
        return;

    std::string header, payload, retpayload;
    for(auto line : PkgConfig.headerLines){
        if(!line.empty()){
            header += line;
        }
    }

    for(auto line : PkgConfig.paylaodLines){
        if(!line.empty()){
            payload += line;
        }
    }

    std::string tmp = header + payload;
    retpayload = SHexIns.ParserHexMsg(tmp);

    client->SendMessage(retpayload);

    if(EMTIMERTYPE::NOTIMER != PkgConfig.tType){
        uint64_t nTime = TimeArr[PkgConfig.tType - 1];
        Statics::g_Timer.Add(nTime, [=](){
            client->SendMessage(retpayload);
        });
    }
}

void PkgHandler::TcpHexRecvHandle(ClientBase *clt, const std::__cxx11::string &payload)
{
    std::string msg = SHexIns.DeparserMsgToHexStr(payload);
    QString qMsg = QString::fromStdString(msg);
    emit(EventMessageSignal(qMsg));
}

void PkgHandler::UdpHandle(const PackageConfig &PkgConfig)
{
    ClientBase* client = GetOrCreateClt(PkgConfig);
    if(!client)
        return;
}

//slots
void PkgHandler::EventLogSlot(QString log)
{
    emit(EventLogSignal(log));
}

void PkgHandler::CloseConnectSlot(EndPort ePort)
{
    emit(CloseConnectSignal(ePort));
}

void PkgHandler::EventMessageSlot(EndPort ePort, std::__cxx11::string msg)
{
    ClientBase * clt = mConnectClt[ePort];
    if(nullptr != clt){
        ExecuteRecv(clt, msg);
    }
}

