#ifndef STATICS_H
#define STATICS_H

#include <Common/singleton.h>
#include <Common/timer.h>
class Statics
{
public:
    Statics();

    static void Init();

    static Timer g_Timer;
};

#endif // STATICS_H
