#include "MotorTask.h"

MotorTask::MotorTask(ServoMotor* motor, Sonar* sonar, Potentiometer* potentiometer) : motor(motor), sonar(sonar), potentiometer(potentiometer) {}

void MotorTask::init(const unsigned long period) {
    Task::init(period);
}

void MotorTask::tick() {
  if (Scheduler::getState() == State::ALARM) {
    int angle = Scheduler::isManual() ? potentiometer->read() :
                                        map(sonar->read()*100, WLMAX*100, WL2*100, 180, 0);
    motor->move(angle);
  }
}
