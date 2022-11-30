#include "Lcd.h"

Lcd::Lcd(const uint8_t address, const uint8_t columns, const uint8_t rows) : LiquidCrystal_I2C(address, columns, rows) {
  this->on = false;
  this->init();
}

void Lcd::turnOn() {
  //tutte le volte pulisco lo schermo e rimetto il cursore a zero
    this->clear();
    if (!on) {
      //se non è già acceso accendo il display e la luce
      this->on = true;
      this->display();
      this->backlight();
    }
}

void Lcd::turnOff() {
    if (on) {
      //se non è già spento spengo il display e la luce
      this->on = false;
      this->noDisplay();
      this->noBacklight();
    }
}

void Lcd::write(const int col, const int row,  String phrase) {
  //prendo la posizone de cursore e la stringa
  this->setCursor(col, row);
  this->print(phrase);
}
