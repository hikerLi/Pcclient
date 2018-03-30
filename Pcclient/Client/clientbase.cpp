#include "clientbase.h"

ClientBase::ClientBase(const PackageConfig &PkgConfig) : pType(PkgConfig.pType), sType(PkgConfig.sType)
{
    qRegisterMetaType<EndPort>("EndPort");
    qRegisterMetaType<std::string>("std::string");
}

bool ClientBase::IsConnect()
{
    return bConnect;
}
