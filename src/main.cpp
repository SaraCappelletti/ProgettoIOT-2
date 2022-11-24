#include "Const.h"

#include "Scheduler.h"
#include "Timer.h"
#include "LaTask.h"
#include "LbTask.h"

Scheduler sched;

void setup() {
  Serial.begin(9600);
  Led ledA(LED_A);
  Led ledB(LED_B);

  Photoresistor photoresistor(PHOTORESISTOR);
  Pir pir(PIR);

  sched.init(100);
  
  LaTask laTask(&ledA, &photoresistor, &pir);
  laTask.init(300); // TO FIX
  sched.addTask(&laTask);

  LbTask lbTask(&ledB);
  lbTask.init(300); // TO FIX
  sched.addTask(&lbTask);
}

void loop() {
  sched.schedule();
}
