#include "Task.h"
#include "Component.h"

Task::Task(const unsigned long period) : myPeriod(period) {}

void Task::init() {
  timeElapsed = 0;
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

void Task::addComponent(const Component* const component) {
  Task::components[numComponents++] = component;
}
