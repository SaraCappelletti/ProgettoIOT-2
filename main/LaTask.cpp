#include "LaTask.h"
#include <stdio.h>

LaTask::LaTask(int pin){
    this->pin = pin;
}

void LaTask::init(){
    ledState = OFF;
}

void LaTask::tick(){
    switch (ledState)
    {
    case OFF:
        printf("Accendo");
        ledState = ON;
        break;
    
    case ON:
        printf("Spengo");
        ledState = OFF;
        break;
    }
}