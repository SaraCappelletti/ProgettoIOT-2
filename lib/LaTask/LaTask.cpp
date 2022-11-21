#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(const int pin) : led(pin) {
  this->pin = pin;
}

void LaTask::init(const int period) {
  Task::init(period);
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