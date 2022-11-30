#ifndef __CommunicationTask__
#define __CommunicationTask__

#include "Arduino.h"
#include "Task.h"
#include "Sonar.h"
#include "Scheduler.h"
#include "ServoMotor.h"
#include "Led.h"

class CommunicationTask : public Task {
    Sonar* sonar;
    ServoMotor* motor;
    Led* led;

public:
    CommunicationTask(Sonar* sonar, ServoMotor* motor, Led* led);
    void init(const unsigned long period);
    void tick();
    void send();
    int receive();
};

#endif
