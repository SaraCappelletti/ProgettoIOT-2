#ifndef __CommunicationTask__
#define __CommunicationTask__

#include "Arduino.h"
#include "Task.h"
#include "Sonar.h"
#include "Scheduler.h"
#include "ServoMotor.h"

class CommunicationTask : public Task {
    Sonar* sonar;
    ServoMotor* motor;
    
public:
    CommunicationTask(Sonar* sonar, ServoMotor* motor);
    void init(const unsigned long period);
    void tick();
    void send();
    int receive();
};

#endif
