#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Task.h"
#include "Const.h"
//#include "Timer.h"

enum State {NORMAL, PREALARM, ALARM};

class Scheduler {
  static State state;
  static bool manual;
  static bool remote;

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
  static const char* getStateToString();
  static void setState(const State state);
  static bool isManual();
  static void setManual(bool manual);
  static bool isRemote();
  static void setRemote(bool remote);
};

#endif
