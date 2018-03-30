#ifndef PKGHANDLER_H
#define PKGHANDLER_H

#include <QObject>
#include <unordered_map>
#include <Common/common.h>
#include <Client/clientbase.h>

class PkgHandler : public QObject
{
    Q_OBJECT
public:
    PkgHandler();

    void Execute(const PackageConfig& PkgConfig);

    void ExecuteRecv(ClientBase* clt, const std::string& payload);
protected:
    template<class TargetType, class FuncType>
    void Add(uint32_t ProtoType, uint32_t StreamType,TargetType* target, FuncType&& func);

    template<class TargetType, class FuncType>
    void AddRecv(EMPROTOTYPE, EMSTREAMTYPE, TargetType* target, FuncType&& func);
private:
    typedef std::unordered_map<uint32_t, std::function<void(PackageConfig PkgConfig)>> PKGConfigType;
    //sender dispacher
    std::unordered_map<uint32_t, PKGConfigType> handlers;

    //receiver
    typedef std::unordered_map<uint32_t, std::function<void(ClientBase*, std::string)>> PKGRecvType;

    std::unordered_map<uint32_t, PKGRecvType> recvhandlers;
private:
    void TcpHexHandle(const PackageConfig& PkgConfig);

    void TcpHexRecvHandle(ClientBase* clt, const std::string& payload);

    void UdpHandle(const PackageConfig& PkgConfig);

    ClientBase* GetOrCreateClt(const PackageConfig& PkgConfig);
private:

    std::unordered_map<EndPort, ClientBase*, EndPort_hash, EndPort_Eq> mConnectClt;

    //receiver dispacher
    std::unordered_map<EndPort, ClientBase*, EndPort_hash, EndPort_Eq> mRecvClt;
signals:
    void EventLogSignal(QString);

    void CloseConnectSignal(EndPort);

    void EventMessageSignal(/*EndPort ePort, */QString msg);

public slots:
    void EventLogSlot(QString);

    void CloseConnectSlot(EndPort);

    void EventMessageSlot(EndPort ePort, std::string msg);
};

#endif // PKGHANDLER_H
