/*
 * Ping.h
 *
 * Created: 27-09-2017 15:07:26
 *  Author: Andreas Hervert Nielsen
 */ 

/*Begining of Auto generated code by Atmel studio */

#include <Arduino.h>

 #define rfReceivePin A0 
 

unsigned long ping(int tower);
unsigned long distance = 0;
unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value



  const int echoPin = 3; 
  const int trigPin = 11;
  const int VVCa = 12;
  const int VVCb = 2;
   const int ledPin = 13; 
  


void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(VVCa, OUTPUT);
  pinMode(VVCb, OUTPUT);
    pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() 
{
  char duration = 0;

  Serial.begin(9600);
  digitalWrite(VVCa, HIGH);
  digitalWrite(VVCb, HIGH);

   while(1)
   {
        data=analogRead(rfReceivePin);    //listen for data on Analog pin 0
     
      if(data>upperThreshold){
       digitalWrite(ledPin, LOW);   //If a LOW signal is received, turn LED OFF
       Serial.println(data);
     }
     
     if(data<lowerThreshold){
       digitalWrite(ledPin, HIGH);   //If a HIGH signal is received, turn LED ON
       Serial.println(data);
     }
   }

}


     
