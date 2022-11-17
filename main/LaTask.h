#ifndef __LATASK__
#define __LATASK__

#include "Task.h"

class LaTask: public Task{
    int pin;
    enum{ON, OFF} ledState;

    public:
        LaTask(int pin);
        void init();
        void tick();
};

#endif