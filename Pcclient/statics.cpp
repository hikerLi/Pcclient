#include "statics.h"

Timer Statics::g_Timer;
Statics::Statics()
{

}

void Statics::Init()
{
    g_Timer.Start();
}
