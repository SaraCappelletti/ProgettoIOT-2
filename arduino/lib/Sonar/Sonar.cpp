#include "Sonar.h"
#include "Const.h"

Sonar::Sonar(const int trigPin, const int echoPin) : Sensor(trigPin), echoPin(echoPin) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
}

float Sonar::read() {
  digitalWrite(pin,LOW);
  delayMicroseconds(3);
  digitalWrite(pin,HIGH);
  delayMicroseconds(5);
  digitalWrite(pin,LOW);

  float tUS = pulseIn(echoPin, HIGH);
  float t = tUS / 1000.0 / 1000.0 / 2;
  float distance = t*vs;
  //Serial.println(distance);
  return distance < WLMAX ? WLMAX : distance;
}
