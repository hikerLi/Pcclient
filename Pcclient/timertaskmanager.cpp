#include "timertaskmanager.h"


TimerTaskManager::TimerTaskManager()
{

}

void TimerTaskManager::Start()
{
    mThread = new std::thread([&](){
        bRunning.store(true);
        Run();
    });
}

void TimerTaskManager::PushTimerTask(const std::__cxx11::string &payload, uint8_t prototype, uint64_t timer)
{
    TimerTask* task = TimerTask::CreateTimerTask(payload, prototype, timer);
    mTimerTaskQue.push(task);
}

void TimerTaskManager::Run()
{
    std::unique_lock<std::mutex> uLock(mMutex);
    while(bRunning){
        mCondition.wait(uLock, [&](){
            return !mTimerTaskQue.empty();
        });

        const TimerTask* task = mTimerTaskQue.top();
        if(task->nextTriggerTime >= GetCurrentTime()){
            mTimerTaskQue.pop();
            SendTask(task);
            PushTimerTask(task->payload, task->protoType, task->timer);
            TimerTask::DestroyTimerTask(task);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void TimerTaskManager::SendTask(const TimerTask *task)
{
    if(task->protoType){

    }
}
