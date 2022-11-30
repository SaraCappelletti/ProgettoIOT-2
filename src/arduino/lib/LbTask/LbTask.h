#ifndef __LBTASK__
#define __LBTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"

class LbTask : public Task {
  Led* led;

  public:
    LbTask(Led* led);
    void init(const unsigned long period);
    void tick();
};

#endif
