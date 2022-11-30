#include "Sonar.h"
#include "Const.h"

Sonar::Sonar(const int trigPin, const int echoPin) : Sensor(trigPin), echoPin(echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

float Sonar::read() {
  //mando e aspetto che torni indietro
  digitalWrite(pin,LOW);
  delayMicroseconds(3);
  digitalWrite(pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(pin,LOW);

  float tUS = pulseIn(echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float distance = t*vs;
  // se i valori sono troppo alti o troppo bassi ritorno WLMAX o WLMIN
  return  distance < WLMAX ? WLMAX : 
          distance > WLMIN ? WLMIN :
          distance;
}
