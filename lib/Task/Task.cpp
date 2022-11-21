#include "Task.h"
#include "Component.h"

void Task::init(const int period) {
  myPeriod = period;
  timeElapsed = 0;
}

bool Task::updateAndCheckTime(const int basePeriod) {
  timeElapsed += basePeriod;
  if(timeElapsed >= myPeriod) {
    timeElapsed = 0;
    return true;
  } else {
    return false;
  }
}

void Task::addComponent(const Component* const component) {
  Task::components[numComponents++] = component;
}
