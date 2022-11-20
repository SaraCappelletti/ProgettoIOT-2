#include "Scheduler.h"

State Scheduler::state;

void Scheduler::init(int basePeriod) {
  this->basePeriod = basePeriod;
  timer.setupPeriod(basePeriod);
  nTasks = 0;
}

bool Scheduler::addTask(Task *task) {
  if (nTasks > MAXNTASK - 1) {
    taskList[nTasks] = task;
    nTasks++;
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