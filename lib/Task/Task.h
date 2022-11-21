#ifndef __TASK__
#define __TASK__

#include "Component.h"

#define MAX_COMPONENTS 10

class Task {
  unsigned long myPeriod;
  unsigned long timeElapsed;
  int numComponents;
  const Component* components[MAX_COMPONENTS];
  
  public:
    virtual void init(const int period);
    virtual void tick() = 0;
    bool updateAndCheckTime(const int basePeriod);
    void addComponent(const Component* const component);
};

#endif
