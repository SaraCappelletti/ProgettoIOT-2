#include "Scheduler.h"

State Scheduler::state;

Scheduler::Scheduler(const unsigned long basePeriod) : basePeriod(basePeriod) {}

void Scheduler::init() {
  timer.setupPeriod(basePeriod);
  nTasks = 0;
}

bool Scheduler::addTask(const Task* const task) {
  if (nTasks > MAXNTASK - 1) {
    taskList[nTasks++] = task;
    return true;
  } else {
    return false;
  }
}

void Scheduler::schedule() {
  timer.waitForNextTick();
  for (int i = 0; i < nTasks; i++) {
    if (taskList[i]->updateAndCheckTime(basePeriod)) {
      taskList[i]->tick();
    }
  }
}

State Scheduler::getState() { return Scheduler::state; }

void Scheduler::setState(const State state) { Scheduler::state = state; }
