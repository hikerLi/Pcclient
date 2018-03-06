#ifndef TIMERTASKMANAGER_H
#define TIMERTASKMANAGER_H

#include <string>
#include <queue>
#include <time.h>

struct TimerTask
{
    std::string payload;
    uint64_t timer;
    uint64_t nextTriggerTime;
    TimerTask(const std::string& payload, uint64_t timer) :
        payload(payload), timer(timer), nextTriggerTime(time(NULL) + timer){}
};


class TimerTaskCompare
{
    bool operator()(const TimerTask& left, const TimerTask& right) const
    {
        return left.nextTriggerTime < right.nextTriggerTime;
    }

};

class TimerTaskManager final
{
public:
    TimerTaskManager();

    void Start();


protected:
    void Run();
private:

    std::priority_queue<TimerTask, TimerTaskCompare> mTimerTaskQue;
};

#endif // TIMERTASKMANAGER_H
