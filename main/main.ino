#include"Timer.h"
#include"LaTask.h"

Timer timer;
LaTask laTask(2);

void setup(){
    laTask.init();
    timer.setupPeriod(500);
}

void loop(){
    timer.waitForNextTick();
    laTask.tick();
}