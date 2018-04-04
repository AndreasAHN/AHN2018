/*
 * Ping.h
 *
 * Created: 27-09-2017 15:07:26
 *  Author: Andreas Hervert Nielsen
 */ 

/*Begining of Auto generated code by Atmel studio */

#include <Arduino.h>,

 #define rfReceivePin A0 
 

unsigned long ping(int tower);
void clearScreen();



unsigned long distance = 0;
unsigned int data = 0;   // variable used to store received data
 const unsigned int upperThreshold = 70;  //upper threshold value
 const unsigned int lowerThreshold = 50;  //lower threshold value

  const int ledPin = 13; 
  const int echoPin = 52; 
  const int trigPin = 12;
  const int VVCa = 13;
  const int VVCb = 48;
  const int reciver = 2;
  


void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(VVCa, OUTPUT);
  pinMode(VVCb, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(reciver, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() 
{
  long duration = 0;
  int duration2 = 0;
  Serial.begin(9600);
  digitalWrite(VVCa, HIGH);
  digitalWrite(VVCb, HIGH);
digitalWrite(trigPin, HIGH);
   while(1)
   {
     Serial.print("\n");
      duration2 = digitalRead(reciver);
      duration = analogRead(rfReceivePin);    //listen for data on Analog pin 0
          Serial.print(duration);
          Serial.print("/t");
          Serial.print(duration2);
      /*
      Serial.print("\n Ping er: ");
      Serial.print(ping(1));
      delay(100);
      */
      delay(100);
      }

}




unsigned long ping(int tower)
  {
    unsigned int distanceAvg = 0;
    long duration = 0, distance = 0;

    if (tower == 1)
    {
      
      digitalWrite(trigPin, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin, LOW);
      delayMicroseconds(10); // Added this line
      
      Serial.print("\n");
      while(duration < lowerThreshold)
      {
          digitalWrite(ledPin, HIGH);
          duration = analogRead(rfReceivePin);    //listen for data on Analog pin 0
          Serial.print(duration);
          Serial.print("\n");
          distance ++;
      }
      digitalWrite(ledPin, LOW);
      clearScreen();
      Serial.print("\n");
    }

    return distance;
  }


    void clearScreen()
  {
  Serial.write(27);
  Serial.print("[2J"); // clear screen
  Serial.write(27);
  Serial.print("[H"); // cursor to home
  }
