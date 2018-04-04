
#include <Arduino.h>

void vandPumpe(bool state);
void ventil(int ventil, bool state);
//Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
unsigned long vandStand();
void alarm();



//Intieringer af inputs og outputs
//Digitale
const int pumpe	= 2;
const int ventil1 = 3;
const int ventil2 = 4;
const int ventil3 = 5;

const int buzzer = 6;
const int echoPin = 7; // Ultrasound signal pin
const int trigPin = 8;