#ifndef __LATASK__
#define __LATASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"

class LaTask : public Task {
  int pin;
  Led led;

  public:
    LaTask(const int pin);
    void init(const int period);
    void tick();
};

#endif
