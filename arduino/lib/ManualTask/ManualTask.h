#ifndef __MANUALTASK__
#define __MANUALTASK__

#include "Scheduler.h"
#include "Task.h"
#include "Sonar.h"
#include "Button.h"
#include "Potentiometer.h"

class ManualTask : public Task {
  Potentiometer* potentiometer;
  Sonar* sonar;
  Button* button;

  public:
    ManualTask(Potentiometer* potentiometer, Sonar* sonar, Button* button);
    void init(const unsigned long period);
    void tick();
};

#endif
