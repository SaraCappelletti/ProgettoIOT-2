#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Timer.h"
#define MAXNTASK 10

enum State {NORMAL, PREALARM, ALARM};

class Scheduler {
  static State state;

  unsigned long basePeriod;
  int nTasks;
  Task* taskList[MAXNTASK];
  Timer timer;

public:
  void init(int basePeriod);
  virtual bool addTask(const Task* const task);
  virtual void schedule();
  static State getState();
  static void setState(const State state);
};

#endif
