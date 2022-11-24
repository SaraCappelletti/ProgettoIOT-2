#ifndef __LCTASK__
#define __LCTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"

class LcTask : public Task {
  Led* led;

  public:
    LcTask(Led* led);
    void init(const unsigned long period);
    void tick();
};

#endif
