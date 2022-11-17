#ifndef __LED__
#define __LED__

class Led
{
    const int pin;
    enum {ON, OFF, BLINK} state;
    
    public:
        Led(const int pin); 
        void turnOn();
        void turnOff();
        void setBlinking(const long int unsigned timeOn, const long int unsigned timeOff);
};

#endif