#include "WLTask.h"
#include "Arduino.h"

WLTask::WLTask(Sonar* sonar) : sonar(sonar) {}

void WLTask::init(const unsigned long period) {
    Task::init(period);
}

void WLTask::tick() {
  const float wl = sonar->read();
  if (wl > WL1) {
    Scheduler::setState(NORMAL);
    Task::setPeriod(SONAR_NORMAL_PERIOD);
  } else if (wl > WL2) {
    Scheduler::setState(PREALARM);
    Task::setPeriod(SONAR_PREALARM_PERIOD);
  } else if (wl > WLMAX) {
    Scheduler::setState(ALARM);
    Task::setPeriod(SONAR_ALARM_PERIOD);
  }
}
