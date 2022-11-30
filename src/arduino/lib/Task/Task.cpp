#include "Task.h"
#include "Component.h"

void Task::init(const unsigned long period) {
  Task::myPeriod = period;
  timeElapsed = 0;
  active = true;
}

bool Task::updateAndCheckTime(const unsigned long basePeriod) {
  timeElapsed += basePeriod;
  if (timeElapsed >= myPeriod) {
    timeElapsed = 0;
    return true;
  } else {
    return false;
  }
}

void Task::setPeriod(const unsigned long period) {
  if (this->myPeriod != period) {
    this->myPeriod = period;
  }
}
