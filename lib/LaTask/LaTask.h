#ifndef __LATASK__
#define __LATASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"
#include "Photoresistor.h"
#include "Pir.h"

#define T1 10000.0

class LaTask : public Task {
  float time = 0.0;

  public:
    LaTask(const unsigned long period);
    void init(const unsigned long period, const Led* led, const Photoresistor* photoresistor, const Pir* pir);
    void tick();
};

#endif
