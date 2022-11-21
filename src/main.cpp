#include"Timer.h"
#include"LaTask.h"
#include "Scheduler.h"

Scheduler sched(50);

void setup() {
    
  sched.init();
  
  Task* t0 = new LaTask(13, 500);
  t0->init();
  sched.addTask(t0);
}

void loop() {
  sched.schedule();
}