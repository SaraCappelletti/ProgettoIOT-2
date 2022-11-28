#include "Const.h"

#include "Scheduler.h"
#include "Timer.h"
#include "LaTask.h"
#include "LbTask.h"
#include "LcTask.h"
#include "WLTask.h"
#include "LcdTask.h"
#include "MotorTask.h"

Scheduler sched(SCHEDULER_PERIOD);

void setup() {
  Serial.begin(9600);
  Led ledA(LED_A);
  Led ledB(LED_B);
  Led ledC(LED_C);
  Sonar sonar(TRIG, ECHO);
  Photoresistor photoresistor(PHOTORESISTOR);
  ServoMotor servoMotor(SERVOMOTOR);
  Pir pir(PIR);
  Lcd lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

  sched.init();
  
  LaTask laTask(&ledA, &photoresistor, &pir);
  laTask.init(LIGHT_PERIOD); // TO FIX
  sched.addTask(&laTask);

  LbTask lbTask(&ledB);
  lbTask.init(LIGHT_PERIOD); // TO FIX
  sched.addTask(&lbTask);

  LcTask lcTask(&ledC);
  lcTask.init(LIGHT_PERIOD); // TO FIX
  sched.addTask(&lcTask);

  WLTask wlTask(&sonar);
  wlTask.init(SONAR_NORMAL_PERIOD); // TO FIX
  sched.addTask(&wlTask);

  LcdTask lcdTask(&lcd, &sonar);
  lcdTask.init(LCD_PERIOD); // TO FIX
  sched.addTask(&lcdTask);

  MotorTask motorTask(&servoMotor, &sonar);
  motorTask.init(MOTOR_PERIOD); // TO FIX
  sched.addTask(&motorTask);
}

void loop() {
  sched.schedule();
}
