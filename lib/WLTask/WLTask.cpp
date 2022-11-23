#include "WLTask.h"

WLTask::WLTask(Sonar& sonar) : sonar(sonar) {}

void WLTask::init(const unsigned long period) {
    Task::init(period);
}

void WLTask::tick() {
  if(sonar.read() < WL1) {
    Scheduler::setState(NORMAL);
  }
  else if (sonar.read() < WL2){
    Scheduler::setState(PREALARM);
  }
  else if (sonar.read() < WLMAX){
    Scheduler::setState(ALARM);
  }
}
