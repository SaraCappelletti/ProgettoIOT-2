#ifndef __LCD__
#define __LCD__

#include "Arduino.h"
#include "Const.h"
#include "LiquidCrystal_I2C.h"
#include "Scheduler.h"

class Lcd : public LiquidCrystal_I2C {
  bool on;
  
  public:
    Lcd(const uint8_t address, const uint8_t columns, const uint8_t rows); 
    void turnOn();
    void turnOff();
    void write(const int col, const int row, String phrase);
};

#endif
