#ifndef __LATASK__
#define __LATASK__

#include "Scheduler.h"
#include "Task.h"
#include "Led.h"
#include "Photoresistor.h"
#include "Pir.h"
#include "Const.h"

class LaTask : public Task {
  Led* led;
  Photoresistor* photoresistor;
  Pir* pir;
  float time = 0.0;

  public:
    LaTask(Led* led, Photoresistor* photoresistor, Pir* pir);
    void init(const unsigned long period);
    void tick();
};

#endif
