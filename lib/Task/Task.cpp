#include "Task.h"
#include "Component.h"

void Task::init(const unsigned long period) {
  Task::myPeriod = period;
  timeElapsed = 0;
  active = true;
}

bool Task::updateAndCheckTime(const unsigned long basePeriod) {
  timeElapsed += basePeriod;
  if(timeElapsed >= myPeriod) {
    timeElapsed = 0;
    return true;
  } else {
    return false;
  }
}

bool Task::isActive() {
  return active;
}

void Task::setActive(const bool active) {
  this->active = active;
}
