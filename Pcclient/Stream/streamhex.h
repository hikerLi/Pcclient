#ifndef STREAMHEX_H
#define STREAMHEX_H

#include <string>
#include <Common/singleton.h>
class StreamHex : public Singleton<StreamHex>
{
public:
    StreamHex();

    std::string ParserHexMsg(const std::string& hexStr);
    std::string DeparserMsgToHexStr(const std::string& msgStr);
};

#define SHexIns StreamHex::GetInstance()

#endif // STREAMHEX_H
