#ifndef __TASK__
#define __TASK__

#include "Component.h"

#define MAX_COMPONENTS 10

class Task {
  protected:
    unsigned long myPeriod;
    unsigned long timeElapsed;
    bool active;
  
  public:
    virtual void init(const unsigned long period);
    virtual void tick();
    bool updateAndCheckTime(const unsigned long basePeriod);
    void setPeriod(const unsigned long period);
};

#endif
