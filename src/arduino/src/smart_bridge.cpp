//Di Cappelletti Sara e Beleffi Leonardo

#include "Const.h"
#include "Scheduler.h"
#include "LaTask.h"
#include "LbTask.h"
#include "LcTask.h"
#include "WLTask.h"
#include "LcdTask.h"
#include "MotorTask.h"
#include "ManualTask.h"
#include "CommunicationTask.h"

Scheduler sched(SCHEDULER_PERIOD);

void setup() {
  Serial.begin(9600);
  Led ledA(LED_A);
  Led ledB(LED_B);
  Led ledC(LED_C);
  Sonar sonar(TRIG, ECHO);
  Photoresistor photoresistor(PHOTORESISTOR);
  Potentiometer potentiometer(POTENTIOMETER);
  Button button(BUTTON);
  ServoMotor servoMotor(SERVOMOTOR);
  Pir pir(PIR);
  Lcd lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

  sched.init();
  
  LaTask laTask(&ledA, &photoresistor, &pir);
  laTask.init(LIGHT_PERIOD);
  sched.addTask(&laTask);

  LbTask lbTask(&ledB);
  lbTask.init(LIGHT_PERIOD);
  sched.addTask(&lbTask);

  LcTask lcTask(&ledC);
  lcTask.init(LIGHT_PERIOD);
  sched.addTask(&lcTask);

  WLTask wlTask(&sonar);
  wlTask.init(SONAR_NORMAL_PERIOD);
  sched.addTask(&wlTask);

  LcdTask lcdTask(&lcd, &sonar, &servoMotor);
  lcdTask.init(LCD_PERIOD);
  sched.addTask(&lcdTask);

  ManualTask manualTask(&button);
  manualTask.init(MANUAL_PERIOD);
  sched.addTask(&manualTask);

  MotorTask motorTask(&servoMotor, &sonar, &potentiometer);
  motorTask.init(MOTOR_PERIOD);
  sched.addTask(&motorTask);

  CommunicationTask communicationTask(&sonar, &servoMotor, &ledA);
  communicationTask.init(COMMUNICATION_PERIOD);
  sched.addTask(&communicationTask);
}

void loop() {
  sched.schedule();
}
