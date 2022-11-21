#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(const int pin, const unsigned long period) : Task(period) {
  int i;
  /* aggiungere il led */
}

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
