#ifndef __TASK__
#define __TASK__

#include "Component.h"

#define MAX_COMPONENTS 10

class Task {
  int myPeriod;
  int timeElapsed;
  int numComponents;
  Component components[MAX_COMPONENTS];
  
  public:
    virtual void init(const int period);
    virtual void tick() = 0;
    bool updateAndCheckTime(const int basePeriod);
    void addComponent(const Component component);
};

#endif