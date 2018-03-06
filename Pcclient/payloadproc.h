#ifndef PAYLOADPROC_H
#define PAYLOADPROC_H

#include <string>

class PayloadProc
{
public:
    PayloadProc();

    std::string CombinSenderPayload(const std::string& header, const std::string& payload);
};

#endif // PAYLOADPROC_H
