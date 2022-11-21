#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(const unsigned long period) : Task(period) {}

void LaTask::init() {
}

void LaTask::tick() {
  switch (Scheduler::getState()) {
    case State::ALARM: {
      break;
    }
    default: {
      if(1)
      break;
    }
  }
}
