/*
 * Raket.h
 *
 * Created: 21-08-2017 16:00:00
 *  Author: Andreas Hervert Nielsen
 */ 

/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

  //Inkluderede funktioner:

    //Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
    unsigned long afstandStandFront();
    unsigned long afstandStandBag();
    void alarm();
    void display(int x1, int x2, int x3, int x4, int x5, int x6);
    //Til displayet
    void displayKommand(int tag);
    void displayTime();
    //returner de 3 tidsværdier
    int getTime(int type);

   //Til stepper
   int hast = 3;
void stepperFrem();

void stepperTilbage();

const int Step1 = 9; //konstant for spole 1
const int Step2 = 10; //konstant for spole 1
const int Step3 = 12; //konstant for spole 2
const int Step4 = 11; //konstant for spole 2
int StepA=1;
int StepB=1;
int i=1;
int h=1;



//Intieringer til beregninger:
int timer1_counter;
  //tiden sættes ind i sekunder. Eks 15:45 = 15*60*60+45*60 = 56700. Eller 23:59:59 = 86399. 00:00:00 = 86400.
  //Men du kan bare skrive det normalt ind i hver boks timer, min og sek.
    unsigned long timer = 14 ;
  unsigned long minutter = 00 ;
  unsigned long sekunder = 00 ;
          //NIX PILLE!!!
          unsigned long tid = timer * 60 * 60 + minutter * 60 + sekunder;

//Intieringer af inputs og outputs



  const int buzzer = 14;
  const int echoPin = 6; // Ultrasound signal pin
  const int trigPin = 5;
  const int echoPin1 = 8; // Ultrasound signal pin
  const int trigPin1 = 7;
  const int ledFrem = 2;
  const int ledTilbage = 13;
  const int ledOn = 4;
  const int ledOff = 3;


void setup() {
Serial.begin(9600);

pinMode(Step1,OUTPUT);
pinMode(Step2,OUTPUT);
pinMode(Step3,OUTPUT);
pinMode(Step4,OUTPUT);

pinMode( buzzer , OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode( ledFrem ,OUTPUT);
pinMode(ledTilbage , OUTPUT);
pinMode(ledOn, OUTPUT);
pinMode(ledOff, OUTPUT);

clock

  
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
  
//Mellem hvilken klokkeslet
  if( getTime(1) > 10 &&  getTime(1) < 16)
  {
  digitalWrite(ledOff, LOW);
  digitalWrite(ledOn, HIGH);
    
  while(afstandStandFront() > 40)
    {
    stepperFrem();
    digitalWrite(ledFrem, HIGH);
    }

  digitalWrite(ledFrem, LOW);
  while(afstandStandBag() > 40 )
    {
    stepperTilbage();
    digitalWrite(ledTilbage, HIGH);
    }
    
  digitalWrite(ledTilbage, LOW);
  
  }
  
  digitalWrite(ledOff, HIGH);
  digitalWrite(ledOn, LOW);

  digitalWrite(Step1,LOW);
  digitalWrite(Step2,LOW);
  digitalWrite(Step3,LOW);
  digitalWrite(Step4,LOW);
}

//til stepper
void stepperFrem()
{
for(i=1;i<=300;i++) //Hvor langt skal armen drejes frem ad. 1,286 er en grad, du kan desunden ikke skrive med komma, så rund til nærmeste hele tal. 
  { 
    if(StepA=1)
    { 
    digitalWrite(Step1,HIGH);
    digitalWrite(Step2,LOW);
    int (StepA++);
    }
    //Her sættes I_A og I_B begge til + (++)
    delay(hast);
    if(StepA==2)
    { 
    digitalWrite(Step3,LOW);
    digitalWrite(Step4,HIGH);
    int (StepA++);
    }
    //Her sættes I_B til - (+-)
    delay(hast);
    if(StepA==3)
    { 
    digitalWrite(Step1,LOW);
    digitalWrite(Step2,HIGH);
    int (StepA++);
    }
    //Her sættes I_A og I_B begge til - (--)
    delay(hast); 
    if(StepA==4)
    { 
    digitalWrite(Step3,HIGH);
    digitalWrite(Step4,LOW);
    int (StepA=1);
    }
    delay(hast);
    //Her sættes I_A begge til + (-+)
  } // Her køre stepmorten fremad
}

void stepperTilbage()
{
  for(h=1;h<=300;h++) //Dette er for at få armen tilbage, sætte den til samme værdi, som du brugte til at få den frem.
  { 
    if(StepB==1)
    { 
    digitalWrite(Step4,HIGH);
    digitalWrite(Step3,LOW);
    int (StepB++);
    }
    //Her sættes I_A og I_B begge til + (++)
    delay(hast);
    if(StepB==2)
    { 
    digitalWrite(Step2,LOW);
    digitalWrite(Step1,HIGH);
    int (StepB++);
    }
    //Her sættes I_B til - (+-)
    delay(hast);
    if(StepB==3)
    { 
    digitalWrite(Step4,LOW);
    digitalWrite(Step3,HIGH);
    int (StepB++);
    }
    //Her sættes I_A og I_B begge til - (--)
    delay(hast); 
    if(StepB==4)
    { 
    digitalWrite(Step2,HIGH);
    digitalWrite(Step1,LOW);
    int (StepB=1);
    }
    delay(hast);
    //Her sættes I_A begge til + (-+)
  }// Her køre stepmorteren bagud
}



  //Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
unsigned long afstandStandFront()
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
  
  unsigned long afstandStandBag()
  {
    unsigned int distanceAvg = 0;
    
    for( unsigned int a = 0; a < 10; a = a + 1 )
    {
      
      long duration, distance;
      digitalWrite(trigPin1, LOW);  // Added this line
      delayMicroseconds(2); // Added this line
      digitalWrite(trigPin1, HIGH);
      delayMicroseconds(10); // Added this line
      digitalWrite(trigPin1, LOW);
      duration = pulseIn(echoPin1, HIGH);
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
