#ifndef __CONST__
#define __CONST__

#define MAXNTASK 10
#define CALIBRATION_TIME 1000 // milliseconds

#define THL 800
#define T1 4000.0
#define TBUTTON 200
#define WLMIN 1.00
#define WL1 0.25
#define WL2 0.15
#define WLMAX 0.02
#define POT_SENSIBILITY 5

#define LED_C 11
#define LED_B 10
#define LED_A 9
#define TRIG 8
#define ECHO 7
#define SERVOMOTOR 4
#define BUTTON 3
#define PIR 2
#define PHOTORESISTOR A1
#define POTENTIOMETER A2
#define LCD_SDA A4
#define LCD_SCL A5

#define LCD_ADDRESS (uint8_t)0x27
#define LCD_COLUMNS (uint8_t)20
#define LCD_ROWS (uint8_t)4

#define SCHEDULER_PERIOD 100
#define LIGHT_PERIOD 200
#define SONAR_NORMAL_PERIOD 300
#define SONAR_PREALARM_PERIOD 200
#define SONAR_ALARM_PERIOD 100 
#define MANUAL_PERIOD 20
#define MOTOR_PERIOD 200
#define LCD_PERIOD 200
#define COMMUNICATION_PERIOD 200

#endif