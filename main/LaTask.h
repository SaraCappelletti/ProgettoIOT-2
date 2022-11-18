#ifndef __LATASK__
#define __LATASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"

class LaTask: public Task{
  int pin;
  Led *led;

  public:
    LaTask(int pin);
    void init(int period);
    void tick();
};

#endif