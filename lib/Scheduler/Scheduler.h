#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Timer.h"
#define MAXNTASK 10

enum State {NORMAL, PREALARM, ALARM};

class Scheduler {
  static State state;

  const unsigned long basePeriod;
  int nTasks;
  const Task* taskList[MAXNTASK];
  Timer timer;

public:
  Scheduler(const unsigned long basePeriod);
  void init();
  virtual bool addTask(const Task* const task);
  virtual void schedule();
  static State getState();
  static void setState(const State state);
};

#endif
