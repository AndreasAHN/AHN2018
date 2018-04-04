/* 
  RF Blink - Transmit sketch 
     Written by ScottC 17 Jun 2014
     Arduino IDE version 1.0.5
     Website: http://arduinobasics.blogspot.com
     Transmitter: FS1000A/XY-FST
     Description: A simple sketch used to test RF transmission.          
 ------------------------------------------------------------- */

 #define rfTransmitPin 11  //RF Transmitter pin = digital pin 4
  #define VCC 12
 #define ledPin 13        //Onboard LED = digital pin 13

 void setup(){
   pinMode(rfTransmitPin, OUTPUT);     
   pinMode(ledPin, OUTPUT);    
   pinMode(VCC, OUTPUT);  
 }

 void loop(){
  digitalWrite(VCC, HIGH);
   while(1)
   {
     digitalWrite(rfTransmitPin, HIGH);     //Transmit a HIGH signal
     digitalWrite(ledPin, HIGH);            //Turn the LED on
     delay(5);                           //Wait for 1 second
     digitalWrite(ledPin, LOW);            //Turn the LED on
     digitalWrite(rfTransmitPin,LOW);      //Transmit a LOW signal
     delay(5); 
   }
   
 }
