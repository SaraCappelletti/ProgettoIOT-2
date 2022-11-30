#include "Scheduler.h"
#include "TimerOne.h"

volatile bool timerFlag;

void timerHandler(void) {
  timerFlag = true;
}

State Scheduler::state;
bool Scheduler::manual;
bool Scheduler::remote;

Scheduler::Scheduler(const unsigned long basePeriod) : basePeriod(basePeriod) {}

void Scheduler::init() {
  timerFlag = false;
  Scheduler::state = NORMAL;
  Scheduler::manual = false;
  Scheduler::remote = false;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
  if (nTasks < MAXNTASK-1) {
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule() {   
  while (!timerFlag) {}
  timerFlag = false;
  for (int i = 0; i < nTasks; i++) {
    if (taskList[i]->updateAndCheckTime(basePeriod)) {
      taskList[i]->tick();
    }
  }
}

State Scheduler::getState() { return Scheduler::state; }

const char* Scheduler::getStateToString() {
  return Scheduler::state == State::NORMAL ?    "NORMAL  \0" : 
         Scheduler::state == State::PREALARM ?  "PREALARM\0" : 
                                                "ALARM   \0";
}

void Scheduler::setState(const State st) {
  if (Scheduler::state != st) {
    Scheduler::state = st;
  }
}

bool Scheduler::isManual() {
  return Scheduler::manual;
}


void Scheduler::setManual(bool manual) {
  Scheduler::manual = manual;
}

bool Scheduler::isRemote() {
  return Scheduler::remote;
}


void Scheduler::setRemote(bool manual) {
  Scheduler::remote = remote;
}
