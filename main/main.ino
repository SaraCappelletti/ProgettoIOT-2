#include"Timer.h"
#include"LaTask.h"

Timer timer;
LaTask latask(2);

void setup(){
    laTask.init();
    timer.setupPeriod(500);
}

void loop(){
    timer.waitForNextTick();
    laTask.tick();
}