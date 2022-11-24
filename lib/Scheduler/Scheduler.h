#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Const.h"
//#include "Timer.h"

enum State {NORMAL, PREALARM, ALARM};

class Scheduler {
  static State state;

  int basePeriod;
  int nTasks;
  Task* taskList[MAXNTASK];
  //Timer timer;

public:
  //bool timerFlag;
  Scheduler(const unsigned long period);
  void init();
  virtual bool addTask(Task* task);
  virtual void schedule();
  static State getState();
  static void setState(const State state);
};

#endif
