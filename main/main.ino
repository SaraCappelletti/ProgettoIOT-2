#include"Timer.h"
#include"LaTask.h"
#include "Scheduler.h"

Scheduler sched;

void setup(){
    
  sched.init(50);
  
  Task* t0 = new LaTask(13);
  t0->init(500);
  sched.addTask(t0);
}

void loop(){
  sched.schedule();
}