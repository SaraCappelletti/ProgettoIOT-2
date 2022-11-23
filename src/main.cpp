#include"Timer.h"
#include"LaTask.h"
#include "Scheduler.h"

Scheduler sched(50);

void setup() {
    
  sched.init();
  const Component* la = new Led(13);
  
  Task* t0 = new LaTask(la);
  t0->init();
  sched.addTask(t0);
}

void loop() {
  sched.schedule();
}
