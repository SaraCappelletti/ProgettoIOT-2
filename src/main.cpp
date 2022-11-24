#include "Const.h"

#include "Scheduler.h"
#include "Timer.h"
#include "LaTask.h"
#include "LbTask.h"

Scheduler sched(50);

void setup() {
  Led ledA(LED_A);
  Led ledB(LED_B);

  Photoresistor photoresistor(PHOTORESISTOR);
  Pir pir(PIR);

  sched.init();
  
  LaTask laTask(&ledA, &photoresistor, &pir);
  laTask.init(300); // TO FIX
  sched.addTask(&laTask);
}

void loop() {
  sched.schedule();
}
