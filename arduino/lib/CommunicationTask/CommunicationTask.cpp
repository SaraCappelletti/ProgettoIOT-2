#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(Sonar* sonar, ServoMotor* motor) : sonar(sonar), motor(motor) {};

void CommunicationTask::init(const unsigned long period) {
    Task::init(period);
}

void CommunicationTask::tick() {
    this->send();
    if (Scheduler::getState() == State::ALARM && Scheduler::isManual() == true) {
        if (Serial.available() > 0) {
            int val = receive();
            motor->move(val);
        }
    }
}

void CommunicationTask::send() {
    float wl = sonar->read();
    Serial.println(millis()/1000.0 + (String)"," + wl);
}

int CommunicationTask::receive() {
    return Serial.read();
}
