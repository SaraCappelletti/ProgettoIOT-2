#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(int pin) {
  this->pin = pin;
}

void LaTask::init(int period) {
  Task::init(period);
  led = new Led(pin);
}

void LaTask::tick() {
  switch (Scheduler::getState()) {
  case State::ALARM:
    printf("Alarm");
    break;
  
  default:
    printf("Spengo");
    break;
  }
}