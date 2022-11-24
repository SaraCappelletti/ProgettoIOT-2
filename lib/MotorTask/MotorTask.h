#ifndef __MOTORTASK__
#define __MOTORTASK__

#include "Scheduler.h"
#include "Task.h"
#include "ServoMotor.h"
#include "Sonar.h"

class MotorTask : public Task {
  ServoMotor* motor;
  Sonar* sonar;

  public:
    MotorTask(ServoMotor* motor, Sonar* sonar);
    void init(const unsigned long period);
    void tick();
};

#endif
