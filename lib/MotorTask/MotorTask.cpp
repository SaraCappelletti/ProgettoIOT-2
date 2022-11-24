#include "MotorTask.h"

MotorTask::MotorTask(ServoMotor* motor, Sonar* sonar) : motor(motor), sonar(sonar) {}

void MotorTask::init(const unsigned long period) {
    Task::init(period);
}

void MotorTask::tick() {
  if (Scheduler::getState() == State::ALARM) {
    Serial.println("motor");
    motor->move(sonar->read());
  }
}
