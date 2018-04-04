
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
  const int disp1 = 22;
  const int disp2 = 23;
  const int disp3 = 24;
  const int disp4 = 25;
  const int hex1  = 26;
  const int hex2  = 27;
  const int hex3  = 28;
  const int hex4  = 29;
  const int hex5  = 30;
  const int hex6  = 31;

  const int pumpe = 36;
  const int ventil1 = 38;
  const int ventil2 = 39;
  const int ventil3 = 40;

  const int buzzer = 4;
  const int echoPin = 2; // Ultrasound signal pin
  const int trigPin = 3;
  //Analog
  int soilSensor1 = 0;
  int soilSensor2 = 1;
  int soilSensor3 = 2;
  int soilSensor4 = 3;
  int soilSensor5 = 4;
  int soilSensor6 = 5;

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

    //digitalWrite(ventil3, HIGH);
    //delay(1000);
    //digitalWrite(ventil3, LOW);
    //delay(1000);

}


int soilSensor(int soilSensor)
{
  int sensorValue = analogRead(soilSensor);

  //Da 820 er max for sensoren, devidere vi 8,2, for at få det om i procent
  int sensorProcent = sensorValue/8.2;

  return sensorProcent;
}

void vandPumpe(unsigned char  state)
  {
    digitalWrite(pumpe, state);
  }

void ventil(int ventil, unsigned char  state)
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
      displayKommand(x1);
    digitalWrite(hex1,LOW);

    delay(1);

    digitalWrite(hex2,HIGH);
      displayKommand(x2);
    digitalWrite(hex2,LOW);

    delay(1);

    digitalWrite(hex3,HIGH);
      displayKommand(x3);
    digitalWrite(hex3,LOW);

    delay(1);

    digitalWrite(hex4,HIGH);
      displayKommand(x4);
    digitalWrite(hex4,LOW);

    delay(1);

    digitalWrite(hex5,HIGH);
      displayKommand(x5);
    digitalWrite(hex5,LOW);

    delay(1);

    digitalWrite(hex6,HIGH);
      displayKommand(x6);
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
  
  }

  //returner de 3 tidsværdier
  void getTime(unsigned int hours&, unsigned int minutes&, unsigned int seconds& )
  {
  hours = tid / 60 / 60;
  minutes = (tid - hours * 60 * 60) / 60;
  seconds = tid - minutes * 60 - hours * 60 * 60;
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
