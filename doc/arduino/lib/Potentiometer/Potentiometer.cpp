#include "Potentiometer.h"

Potentiometer::Potentiometer(const int pin) : Component(pin) {}

int Potentiometer::read() {
  //mappo il valore direttamente in gradi per passare l'angolo al motore
  int value = map(analogRead(pin), 0, 1024, 0 , 180);
  if (abs(prev - value) > POT_SENSIBILITY) {
    //se sono sotto la soglia di sensibilità aggiorno il valore precedente e ritorno il valore nuovo
    prev = value;
    return value;
  }
  //altrimenti ritorno il valore precedente senza cambiare niente
  return prev;
}
