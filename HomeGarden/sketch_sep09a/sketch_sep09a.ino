/*
 * Home_Garden.h
 *
 * Created: 10-08-2017 15:42:53
 *  Author: Andreas Hervert Nielsen
 */ 

/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

  //Inkluderede funktioner:
    int soilSensor(int soilSensor);
    void vandPumpe(bool state);
    void ventil(int ventil, bool state);
    //Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
    unsigned long vandStand();
    void alarm();
    void display(int x1, int x2, int x3, int x4, int x5, int x6);
    //Til displayet
    void displayKommand(int tag);
    void displayTime();
    //returner de 3 tidsværdier
    int getTime(int type);
    
    //Skærm til consol
    void clearScreen();
    void soilDisp();
    void klokken();





//Intieringer til beregninger:
int timer1_counter;
  //tiden sættes ind i sekunder. Eks 15:45 = 15*60*60+45*60 = 56700. Eller 23:59:59 = 86399. 00:00:00 = 86400.
  //Men du kan bare skrive det normalt ind i hver boks timer, min og sek.
  unsigned long timer = 15 ;
  unsigned long minutter = 45 ;
  unsigned long sekunder = 00 ;
          //NIX PILLE!!!
          unsigned long tid = timer * 60 * 60 + minutter * 60 + sekunder;

//Intieringer af inputs og outputs
  //Digitale
  const int pumpe = 2;
  const int ventil1 = 3;
  const int ventil2 = 4;
  const int ventil3 = 5;

  const int buzzer = 6;
  const int echoPin = 7; // Ultrasound signal pin
  const int trigPin = 8;

  const int hex1  = 9;
  const int hex2  = 10;
  const int hex3  = 11;
  const int hex4  = 12;
  const int hex5  = 13;
  const int hex6  = 14;
  const int disp1 = 15;
  const int disp2 = 16;
  const int disp3 = 17;
  const int disp4 = 18;
  
    
  //Analog
  int soilSensor1 = 0;
  int soilSensor2 = 1;
  int soilSensor3 = 2;
  int soilSensor4 = 3;
  int soilSensor5 = 4;
  int soilSensor6 = 5;
  //Analog sensor aflæs buffer:
  int soil1 = 0;
  int soil2 = 0;
  int soil3 = 0;
  int soil4 = 0;
  int soil5 = 0;
  int soil6 = 0;

void setup() {
  Serial.begin(9600);

  pinMode( disp1  , OUTPUT);
  pinMode( disp2  , OUTPUT);
  pinMode( disp3  , OUTPUT);
  pinMode( disp4  , OUTPUT);
  pinMode( hex1 , OUTPUT);
  pinMode( hex2 , OUTPUT);
  pinMode( hex3 , OUTPUT);
  pinMode( hex4 , OUTPUT);
  pinMode( hex5 , OUTPUT);
  pinMode( hex6 , OUTPUT);

  pinMode( pumpe  , OUTPUT);
  pinMode( ventil1 , OUTPUT);
  pinMode( ventil2 , OUTPUT);
  pinMode( ventil3 , OUTPUT);

  pinMode( buzzer , OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


  //Til uret
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  //timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  //timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();
}




















// the loop function runs over and over again forever
void loop() {

    
    vandPumpe(HIGH);
    ventil(1, HIGH);
    ventil(2, LOW);
    ventil(3, LOW);


    delay(1000);
    
    //Aflæsninger af sensor
    soil1 = soilSensor(soilSensor1);
    soil2 = soilSensor(soilSensor2);
    soil3 = soilSensor(soilSensor3);
    soil4 = soilSensor(soilSensor4);
    soil5 = soilSensor(soilSensor5);
    soil6 = soilSensor(soilSensor6);
    
    //Consolskærm
    clearScreen();
    klokken();
    soilDisp();


}



























int soilSensor(int soilSensor)
{
  int sensorValue = analogRead(soilSensor);

  //Da 820 er max for sensoren, devidere vi 8,2, for at få det om i procent
  int sensorProcent = sensorValue/8.2;

  return sensorProcent;
}

void vandPumpe(bool state)
  {
    digitalWrite(pumpe, state);
  }

void ventil(int ventil, bool state)
  {

    switch (ventil)
    {
      case 1:
      digitalWrite(ventil1, state);
      
      case 2:
      digitalWrite(ventil2, state);

      case 3:
      digitalWrite(ventil3, state);
    }
    
  }

  //Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
unsigned long vandStand()
  {
    unsigned int distanceAvg = 0;
    
    for( unsigned int a = 0; a < 10; a = a + 1 )
    {
      
    long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;

    distanceAvg = distanceAvg + distance;
    }
      

    return distanceAvg/10;
  }

void alarm()
{
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}

void display(int x1, int x2, int x3, int x4, int x5, int x6)
{
  int x = 0;

  while(x < 60)
  {
    digitalWrite(hex1,HIGH);
      displayKommand(1);
    digitalWrite(hex1,LOW);

    delay(1);

    digitalWrite(hex2,HIGH);
      displayKommand(2);
    digitalWrite(hex2,LOW);

    delay(1);

    digitalWrite(hex3,HIGH);
      displayKommand(3);
    digitalWrite(hex3,LOW);

    delay(1);

    digitalWrite(hex4,HIGH);
      displayKommand(4);
    digitalWrite(hex4,LOW);

    delay(1);

    digitalWrite(hex5,HIGH);
      displayKommand(5);
    digitalWrite(hex5,LOW);

    delay(1);

    digitalWrite(hex6,HIGH);
      displayKommand(6);
    digitalWrite(hex6,LOW);

    x++;
  }
}


//Til displayet
  void displayKommand(int tag)
  { 
   switch(tag)
   {
    case 0:
      //0
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,LOW);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,LOW);
      delay(1);

    case 1:
      //1
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,LOW);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,HIGH);
      delay(1);

    case 2:
      //2
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,LOW);
      digitalWrite(disp3,HIGH);
      digitalWrite(disp4,LOW);
      delay(1);

    case 3:
       //3
       digitalWrite(disp1,LOW);
       digitalWrite(disp2,LOW);
       digitalWrite(disp3,HIGH);
       digitalWrite(disp4,HIGH);
       delay(1);

    case 4:
      //4
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,HIGH);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,LOW);
      delay(1);

    case 5:
      //5
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,HIGH);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,HIGH);
      delay(1);

    case 6:
      //6
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,HIGH);
      digitalWrite(disp3,HIGH);
      digitalWrite(disp4,LOW);
      delay(1);

    case 7:
      //7
      digitalWrite(disp1,LOW);
      digitalWrite(disp2,HIGH);
      digitalWrite(disp3,HIGH);
      digitalWrite(disp4,HIGH);
      delay(1);

    case 8:
      //8
      digitalWrite(disp1,HIGH);
      digitalWrite(disp2,LOW);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,LOW);
      delay(1);

    case 9:
      //9
      digitalWrite(disp1,HIGH);
      digitalWrite(disp2,LOW);
      digitalWrite(disp3,LOW);
      digitalWrite(disp4,HIGH);
      delay(1);
   }
  }

  void displayTime()
  {
  unsigned tim = getTime(1);
  unsigned min = getTime(2);
  unsigned sec = getTime(3);

  int disp1;
  int disp2;
  int disp3;
  int disp4;
  int disp5;
  int disp6;

  if (tim < 30)
  {
    disp1 = 2;
  }
  else if(tim < 20)
  {
    disp1 = 1;
  }
  else
  {
    disp1 = 0;
  }



  }

  //returner de 3 tidsværdier
  int getTime(int type)
  {
  unsigned int hours;
  unsigned int minutes;
  unsigned int seconds;
  
  switch(type)
  {
    case 1:
      hours = tid / 60 / 60;
      return(hours);

    case 2:
      hours = tid / 60 / 60;
      minutes = (tid - hours * 60 * 60) / 60;
      return(minutes);

    case 3:
      hours = tid / 60 / 60;
      minutes = (tid - hours * 60 * 60) / 60;
      seconds = tid - minutes * 60 - hours * 60 * 60;
      return(seconds);
  }
  }


  void clearScreen()
  {
  Serial.write(27);
  Serial.print("[2J"); // clear screen
  Serial.write(27);
  Serial.print("[H"); // cursor to home
  }

  void soilDisp()
  {
  Serial.print("\n Sensor aflaesning for soil1: ");
  Serial.print(soil1);

  Serial.print("\n Sensor aflaesning for soil2: ");
  Serial.print(soil2);

  Serial.print("\n Sensor aflaesning for soil3: ");
  Serial.print(soil3);

  Serial.print("\n Sensor aflaesning for soil4: ");
  Serial.print(soil4);

  Serial.print("\n Sensor aflaesning for soil5: ");
  Serial.print(soil5);

  Serial.print("\n Sensor aflaesning for soil6: ");
  Serial.print(soil6);
  Serial.print("\n");
  }

  void klokken()
  {
  Serial.print("\n Klokken er: \t");
  Serial.print(getTime(1));
  Serial.print(":");
  Serial.print(getTime(2));
  Serial.print(":");
  Serial.print(getTime(3));
  Serial.print("\n");
  }


//Til uret
ISR(TIMER1_OVF_vect)        // interrupt service routine
{
  TCNT1 = timer1_counter;   // preload timer
  
  if(tid == 86400)
  {
    tid = 0;

  }
  else
  {
    tid = tid + 1;
  }
}
