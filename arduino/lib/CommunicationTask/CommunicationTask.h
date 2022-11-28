#ifndef __CommunicationTask__
#define __CommunicationTask__

#include "Task.h"
#include "Sonar.h"

class CommunicationTask : public Task {
    Sonar* sonar;
    
public:
    CommunicationTask(Sonar* sonar);
    void init(const unsigned long period);
    void tick();
};

#endif
