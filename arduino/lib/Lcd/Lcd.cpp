#include "Lcd.h"

Lcd::Lcd(const uint8_t address, const uint8_t columns, const uint8_t rows) : LiquidCrystal_I2C(address, columns, rows) {
  this->on = false;
  this->init();
}

void Lcd::turnOn(){
    if(!on){
        this->on = true;
        this->display();
        this->backlight();
    }
}

void Lcd::turnOff(){
    if(on){
        this->on = false;
        this->noDisplay();
        this->noBacklight();
    }
}

void Lcd::write(const int col, const int row,  String phrase) {
  this->setCursor(col, row);
  this->print(phrase);
}
