#ifndef __TASK__
#define __TASK__

#include "Component.h"

#define MAX_COMPONENTS 10

class Task {
  protected:
    unsigned long myPeriod;
    unsigned long timeElapsed;
  
  public:
    virtual void init(const unsigned long period);
    virtual void tick() = 0;
    bool updateAndCheckTime(const unsigned long basePeriod);
};

#endif
