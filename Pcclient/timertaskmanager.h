#ifndef TIMERTASKMANAGER_H
#define TIMERTASKMANAGER_H

#include <string>
#include <queue>
#include <time.h>
#include <atomic>
#include <thread>
#include <condition_variable>
#include <chrono>

uint64_t GetCurrentTime()
{
    uint64_t milliseconds_since_epoch = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return milliseconds_since_epoch;
}

struct TimerTask
{

    static TimerTask* CreateTimerTask(const std::string& payload, uint8_t protoType, uint64_t timer){
        return new TimerTask(payload, protoType, timer);
    }

    static void DestroyTimerTask(const TimerTask* task){
        delete task;
    }

    std::string payload;
    uint8_t protoType;
    uint64_t timer;
    uint64_t nextTriggerTime;
    TimerTask(const std::string& payload, uint8_t protoType, uint64_t timer) :
        payload(payload), protoType(protoType), timer(timer), nextTriggerTime(GetCurrentTime() + timer){}
};


class TimerTaskCompare
{
public:
    bool operator()(const TimerTask* left, const TimerTask* right) const
    {
        return left->nextTriggerTime < right->nextTriggerTime;
    }

};

class TimerTaskManager final
{
public:
    TimerTaskManager();

    void Start();

    void PushTimerTask(const std::string& payload, uint8_t prototype, uint64_t timer);
protected:
    void Run();

    void SendTask(const TimerTask* task);
private:

    std::priority_queue<TimerTask*, std::vector<TimerTask*>, TimerTaskCompare> mTimerTaskQue;
    std::atomic_bool bRunning;
    std::thread * mThread;
    std::condition_variable mCondition;
    std::mutex mMutex;
};

#endif // TIMERTASKMANAGER_H
