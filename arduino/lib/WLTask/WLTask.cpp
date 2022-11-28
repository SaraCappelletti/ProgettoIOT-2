#include "WLTask.h"
#include "Arduino.h"

WLTask::WLTask(Sonar* sonar) : sonar(sonar) {}

void WLTask::init(const unsigned long period) {
    Task::init(period);
}

void WLTask::tick() {
  const float wl = sonar->read();
  if(wl > WL1) {
    Scheduler::setState(NORMAL);
  } else if (wl > WL2){
    Scheduler::setState(PREALARM);
  } else if (wl > WLMAX){
    Scheduler::setState(ALARM);
  }
  /*
  const unsigned long wl = sonar->read();
  Scheduler::setState(wl > WLMAX ? ALARM :
                      wl > WL2 ? PREALARM : NORMAL);*/
}