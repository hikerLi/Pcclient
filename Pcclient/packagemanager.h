#ifndef PACKAGEMANAGER_H
#define PACKAGEMANAGER_H

#include <singleton.h>
#include <common.h>
#include <unordered_map>
#include <clientbase.h>

class PackageManager : public Singleton<PackageManager>
{
public:
    PackageManager();

    void Start();

    void SendPackage(const PackageConfig& pConfig);

private:
    std::string ProcessPackage(const PackageConfig& pConfig);

    static void EventLogCB(int severity, const char* msg);
private:
    std::unordered_map<EndPort, ClientBase*, EndPort_hash, EndPort_Eq> mConnectClt;
};


#define PackMgr PackageManager::GetInstance()

#endif // PACKAGEMANAGER_H
