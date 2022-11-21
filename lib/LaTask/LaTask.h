#ifndef __LATASK__
#define __LATASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"

class LaTask : public Task {
  public:
    LaTask(const int pin, const unsigned long period);
    void init();
    void tick();
};

#endif
