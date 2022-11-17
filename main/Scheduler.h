#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Timer.h"
#define MAXNTASK 10

class Scheduler{
    int basePeriod;
    int nTasks;
    Task* taskList[MAXNTASK];
    Timer timer;

public:
    void init(int basePeriod);
    virtual bool addTask(Task* task);
    virtual void schedule();
};

#endif
