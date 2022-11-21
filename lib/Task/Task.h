#ifndef __TASK__
#define __TASK__

#include "Component.h"

#define MAX_COMPONENTS 10

class Task {
  const unsigned long myPeriod;
  unsigned long timeElapsed;
  int numComponents;
  const Component* components[MAX_COMPONENTS];
  
  public:
    Task(const unsigned long period);
    virtual void init();
    virtual void tick() = 0;
    bool updateAndCheckTime(const unsigned long basePeriod);
    void addComponent(const Component* const component);
};

#endif
