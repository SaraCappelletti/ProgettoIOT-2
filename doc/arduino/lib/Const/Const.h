#ifndef __CONST__
#define __CONST__

#define MAXNTASK 10
#define CALIBRATION_TIME 1000 // milliseconds

#define THL 800 //livello in cui la luce è troppa e la smart light non si accende
#define T1 4000.0 //tempo in cui la smart light rimane accesa dopo aver rilevato un movimento
#define TBUTTON 200 // tempo di de-bouncing
#define WLMIN 1.00 //livello dell'acqua oltre cui il sonar non legge
#define WL1 0.25 // primo livello dell'acqua per stare in pre-alarma
#define WL2 0.15 //secondo livello dell'acqua per stare in alarm
#define WLMAX 0.02 //livello dell'acqua oltre cui il sonar non legge
#define POT_SENSIBILITY 5 //per non muovere continuamente il motore settiamo una sensibilità al potenziometro

//i pin su Arduino
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

//i dati da passare al costruttore dell'Lcd
#define LCD_ADDRESS (uint8_t)0x27
#define LCD_COLUMNS (uint8_t)20
#define LCD_ROWS (uint8_t)4

//i periodi dei vari task
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