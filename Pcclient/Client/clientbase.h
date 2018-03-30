#ifndef CLIENTBASE_H
#define CLIENTBASE_H
#include <Common/common.h>
#include <QObject>
#include <QMetaType>

class ClientBase : public QObject
{
    Q_OBJECT
public:
    ClientBase(const PackageConfig &PkgConfig);

    virtual void Start(const EndPort& ePort) = 0;

    virtual bool SendMessage(const std::string& payload) = 0;

    virtual bool IsConnect();

    EMPROTOTYPE GetPType(){
        return pType;
    }

    EMSTREAMTYPE GetSType(){
        return sType;
    }

    EndPort GetEPort(){
        return ePort;
    }
signals:
    void MessageSignal(EndPort ePort, std::string msg);

    void EventSignal(QString msg);

    void CloseConnectSignal(EndPort ePort);

protected:
    bool bConnect;

    EMPROTOTYPE pType;
    EMSTREAMTYPE sType;

    EndPort ePort;
};

#endif // CLIENTBASE_H
