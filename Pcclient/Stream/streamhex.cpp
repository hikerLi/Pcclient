#include "streamhex.h"

StreamHex::StreamHex()
{

}

std::__cxx11::string StreamHex::ParserHexMsg(const std::__cxx11::string &hexStr)
{
    std::string parserpayload;
    uint8_t data = 0;
    uint8_t mul = 1;
    for(auto ch : hexStr){
        if('-' != ch){
            uint8_t tdata = 0;
            if(ch >= '0' && ch <= '9'){
                tdata += ch - '0';
            }else if(ch >= 'A' && ch <= 'Z'){
                tdata += (ch - 'A' + 10);
            }else if(ch >= 'a' && ch <= 'z'){
                tdata += (ch - 'a' + 10);
            }
            data *= mul;
            data += tdata;
            mul *= 16;
        }else{
            parserpayload.push_back(data);
            data = 0;
            mul = 1;
        }
    }
    parserpayload.push_back(data);
    return parserpayload;
}

std::__cxx11::string StreamHex::DeparserMsgToHexStr(const std::__cxx11::string &msgStr)
{
    std::string hexStr;
    for(int32_t index = 0; index < msgStr.length(); ++index){
        uint8_t item = msgStr[index];

        uint8_t first = item / 16;
        uint8_t second = item % 16;
        if(first > 9){
            first = 'A' + (first - 10);
        }else{
            first += '0';
        }
        if(second > 9){
            second = 'A' + (second - 10);
        }else{
            second += '0';
        }

        hexStr.push_back(first);
        hexStr.push_back(second);
        if(index < msgStr.length() - 1)
            hexStr.push_back('-');
    }
    return hexStr;
}
