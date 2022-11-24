/*#include "Scheduler.h"
#include "Arduino.h"

State Scheduler::state;

Scheduler::Scheduler(const unsigned long basePeriod) : basePeriod(basePeriod) {}

void Scheduler::init() {
  Scheduler::state = NORMAL;
  timer.setupPeriod(basePeriod);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task) {
  if (nTasks > MAXNTASK - 1) {
    taskList[nTasks++] = task;
    return true;
  } else {
    return false;
  }
}

void Scheduler::schedule() {
  Serial.println("Schedule");
  timer.waitForNextTick();
  for (int i = 0; i < nTasks; i++) {
    if (taskList[i]->updateAndCheckTime(basePeriod)) {
      Serial.println("tick");
      taskList[i]->tick();
    }
  }
}

State Scheduler::getState() { return Scheduler::state; }

void Scheduler::setState(const State state) { Scheduler::state = state; }*/

#include "Scheduler.h"
#include "TimerOne.h"

volatile bool timerFlag;

void timerHandler(void){
  timerFlag = true;
}

State Scheduler::state;

//Scheduler::Scheduler(const unsigned long basePeriod) : basePeriod(basePeriod) {}

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  Scheduler::state = NORMAL;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(Task* task){
  if (nTasks < MAXNTASK-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule(){   
  while (!timerFlag){
    /*Serial.print("while: ");
    Serial.println(timerFlag);*/
  }
  timerFlag = false;
  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->isActive() && taskList[i]->updateAndCheckTime(basePeriod)){
      taskList[i]->tick();
    }
  }
}

State Scheduler::getState() { return Scheduler::state; }

void Scheduler::setState(const State state) { Scheduler::state = state; }
