/*
 * Home_Garden.h
 *
 * Created: 10-08-2017 15:42:53
 *  Author: Andreas Hervert Nielsen
 */ 

/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
//#include <avr/io.h>
//#include "i2c.h"
//#include "lm75.h"
//#include "mma8652.h"

	//Inkluderede funktioner:
		void initiering();
		int soilSensor(int soilSensor);
		void vandPumpe(bool state);
		void ventil(int ventil, bool state);
		void knapper();
		 int planteVudering(int plante);
		//Via ultralydsensor, kommer tilbage i cm, max afstand 255cm
		unsigned long vandStand();
		void alarm();
		void display(int x1, int x2, int x3, int x4, int x5, int x6);
		//Til displayet
		void displayKommand(int tag);
		void displayTime();
		void vandProcent();
		//returner de 3 tidsværdier
		void getTime(int type);
		
		//Skærm til consol
		void clearScreen();
		void soilDisp();
		void klokken();
		void temper();


		//TIL TEMPERATUR
		//void i2c_init();
		//void i2c_start();
		//void i2c_write(unsigned char data);
		//unsigned char i2c_read (unsigned char isLast);
		//void i2c_stop();
//
		//int LM75_temperature();
//
		//void initAcc();
		//int AccX();
		//int AccY();
		//int AccZ();

//Intieringer til beregninger:
int timer1_counter;
	//tiden sættes ind i sekunder. Eks 15:45 = 15*60*60+45*60 = 56700. Eller 23:59:59 = 86399. 00:00:00 = 86400.
	//Men du kan bare skrive det normalt ind i hver boks timer, min og sek.
	unsigned long timer = 19 ;
	unsigned long minutter = 11 ;
	unsigned long sekunder = 00 ;
					//NIX PILLE!!!
					unsigned long tid = timer * 60 * 60 + minutter * 60 + sekunder;

//Intieringer af inputs og outputs
	//Digitale
	const int pumpe	= 2;
	const int ventil1 = 3;
	const int ventil2 = 4;
	const int ventil3 = 5;

	const int buzzer = 6;
	const int echoPin = 7; // Ultrasound signal pin
	const int trigPin = 8;

	const int hex1	= 14;
	const int hex2	= 15;
	const int hex3	= 16;
	const int hex4	= 17;
	const int hex5	= 18;
	const int hex6	= 19;
	const int disp1	= 30;
	const int disp2	= 31;
	const int disp3	= 32;
	const int disp4	= 33;

	const int knap0 = 22;
	const int knap1 = 23;
	const int knap2 = 24;
	const int knap3 = 25;
	const int knap4 = 26;
	const int knap5 = 27;
	const int knap6 = 28;
	const int knap7 = 29;

	const int led0 = 53;
	const int led1 = 52;
	const int led2 = 51;
	const int led3 = 50;
	const int led4 = 10;
	const int led5 = 11;
	const int led6 = 12;
	const int led7 = 13;
	
		
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



	//Globale variabler:
	int plante1 = 0;
	int plante2 = 0;
	int plante3 = 0;
	int plante4 = 0;
	int plante5 = 0;
	int plante6 = 0;
	int plante7 = 0;

	int vandTilbage = 100;

	int hours;
	int minutes;
	int seconds;


void setup() {
	Serial.begin(9600);

	pinMode( disp1	, OUTPUT);
	pinMode( disp2	, OUTPUT);
	pinMode( disp3	, OUTPUT);
	pinMode( disp4	, OUTPUT);
	pinMode( hex1	, OUTPUT);
	pinMode( hex2	, OUTPUT);
	pinMode( hex3	, OUTPUT);
	pinMode( hex4	, OUTPUT);
	pinMode( hex5	, OUTPUT);
	pinMode( hex6	, OUTPUT);

	pinMode( pumpe	, OUTPUT);
	pinMode( ventil1 , OUTPUT);
	pinMode( ventil2 , OUTPUT);
	pinMode( ventil3 , OUTPUT);

	pinMode( buzzer	, OUTPUT);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

	pinMode(knap0	,	INPUT);
	pinMode(knap1	,	INPUT);
	pinMode(knap2	,	INPUT);
	pinMode(knap3	,	INPUT);
	pinMode(knap4	,	INPUT);
	pinMode(knap5	,	INPUT);
	pinMode(knap6	,	INPUT);
	pinMode(knap7	,	INPUT);

	pinMode(led0	,	OUTPUT);
	pinMode(led1	,	OUTPUT);
	pinMode(led2	,	OUTPUT);
	pinMode(led3	,	OUTPUT);
	pinMode(led4	,	OUTPUT);
	pinMode(led5	,	OUTPUT);
	pinMode(led6	,	OUTPUT);
	pinMode(led7,	OUTPUT);



	//Til uret
	noInterrupts();           // disable all interrupts
	TCCR1A = 0;
	TCCR1B = 0;

	// Set timer1_counter to the correct value for our interrupt interval
	//timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
	//timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
	timer1_counter = 3000;   // preload timer 65536-16MHz/256/2Hz
	
	TCNT1 = timer1_counter;   // preload timer
	TCCR1B |= (1 << CS12);    // 256 prescaler
	TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
	interrupts();
}




















// the loop function runs over and over again forever
void loop() {

	  initiering();
	  
	  while(1)
	  {
			knapper();

			//Aflæsninger af sensor
			soil1 = soilSensor(soilSensor1);
			soil2 = soilSensor(soilSensor2);
			soil3 = soilSensor(soilSensor3);
			soil4 = soilSensor(soilSensor4);
			soil5 = soilSensor(soilSensor5);
			soil6 = soilSensor(soilSensor6);
	  
			//Vudering af plante værdi:
			plante1 = planteVudering(soil1);
			plante2 = planteVudering(soil2);
			plante3 = planteVudering(soil3);
			plante4 = planteVudering(soil4);
			plante5 = planteVudering(soil5);
			plante6 = planteVudering(soil6);

			//Vandtilage
			//vandTilbage = vandStand();
		
			//Consolskærm
			clearScreen();
			Serial.print(tid);
			klokken();
			//temper();
			//vandProcent();
			soilDisp();

		
			digitalWrite(led3, LOW);
			digitalWrite(led2, LOW);

			if (plante2 == 3)
			{
				vandPumpe(LOW);
				delay(3000);
				vandPumpe(HIGH);
				for ( int a = 0; a = 240000; a++ ) 
				{
					clearScreen();
					klokken();
					Serial.print("Taeller til 240000 ud af");
					Serial.print(a);
				}
			}
			else
			{
				vandPumpe(HIGH);
			}

			while (plante2 == 4)
			{
				alarm();
				//Aflæsninger af sensor
				soil1 = soilSensor(soilSensor1);
				soil2 = soilSensor(soilSensor2);
				soil3 = soilSensor(soilSensor3);
				soil4 = soilSensor(soilSensor4);
				soil5 = soilSensor(soilSensor5);
				soil6 = soilSensor(soilSensor6);
			
				//Vudering af plante værdi:
				plante1 = planteVudering(soil1);
				plante2 = planteVudering(soil2);
				plante3 = planteVudering(soil3);
				plante4 = planteVudering(soil4);
				plante5 = planteVudering(soil5);
				plante6 = planteVudering(soil6);
			}
		}

	delay(200);
}























void initiering()
{
	vandPumpe(HIGH);
	ventil(1, HIGH);
	ventil(2, HIGH);
	ventil(3, HIGH);
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
	
	int disp1;
	int disp2;
	int disp3;
	int disp4;
	int disp5;
	int disp6;

	if (hours < 30)
	{
		disp1 = 2;
	}
	else if(hours < 20)
	{
		disp1 = 1;
	}
	else
	{
		disp1 = 0;
	}
  }

  //returner de 3 tidsværdier
  void getTime(int type)
  {
	switch(type)
	{
		case 1:
			hours = tid / 3600;

		case 2:
			hours = tid / 3600;
			minutes = (tid - hours * 3600) / 60;

		case 3:
			hours = tid / 3600;
			minutes = (tid - hours * 3600) / 60;
			seconds = tid - minutes * 60 - hours * 3600;
	} 
  }


  void clearScreen()
  {
  Serial.write(27);
  Serial.print("[2J"); // clear screen
  Serial.write(27);
  Serial.print("[H"); // cursor to home
  }

  void vandProcent()
  {
	  Serial.print("\n Vand tilbage: ");
	  Serial.print(vandStand());
	  Serial.print("cm eller ");
	  Serial.print((100/20)*vandStand());
	  Serial.print("procent brugt \n");
}

  void soilDisp()
  {
  Serial.print("\n Sensor aflaesning for soil1: ");
  Serial.print(soil1);
  
  if (plante1 == 4)
  {
	Serial.print(" = ULTRA ToeR!!!! ");
  }
  else if (plante1 == 3)
  {
	  Serial.print(" = ToeR ");
  }
  else if (plante1 == 2)
  {
	  Serial.print(" = Normal ");
  }
  else if (plante1 == 1)
  {
	  Serial.print(" = Vaad ");
  }
  else if (plante1 == 0)
  {
	  Serial.print(" = Oversvoemmelse!!!! ");
  }


  Serial.print("\n Sensor aflaesning for soil2: ");
  Serial.print(soil2);
    
    if (plante2 == 4)
    {
	    Serial.print(" = ULTRA ToeR!!!! ");
    }
    else if (plante2 == 3)
    {
	    Serial.print(" = ToeR ");
    }
    else if (plante2 == 2)
    {
	    Serial.print(" = Normal ");
    }
    else if (plante2 == 1)
    {
	    Serial.print(" = Vaad ");
    }
    else if (plante2 == 0)
    {
	    Serial.print(" = Oversvoemmelse!!!! ");
    }

  Serial.print("\n Sensor aflaesning for soil3: ");
  Serial.print(soil3);
    
    if (plante3 == 4)
    {
	    Serial.print(" = ULTRA ToeR!!!! ");
    }
    else if (plante3 == 3)
    {
	    Serial.print(" = ToeR ");
    }
    else if (plante3 == 2)
    {
	    Serial.print(" = Normal ");
    }
    else if (plante3 == 1)
    {
	    Serial.print(" = Vaad ");
    }
    else if (plante3 == 0)
    {
	    Serial.print(" = Oversvoemmelse!!!! ");
    }

  Serial.print("\n Sensor aflaesning for soil4: ");
  Serial.print(soil4);
    
    if (plante4 == 4)
    {
	    Serial.print(" = ULTRA ToeR!!!! ");
    }
    else if (plante4 == 3)
    {
	    Serial.print(" = ToeR ");
    }
    else if (plante4 == 2)
    {
	    Serial.print(" = Normal ");
    }
    else if (plante4 == 1)
    {
	    Serial.print(" = Vaad ");
    }
    else if (plante4 == 0)
    {
	    Serial.print(" = Oversvoemmelse!!!! ");
    }

  Serial.print("\n Sensor aflaesning for soil5: ");
  Serial.print(soil5);
    
    if (plante5 == 4)
    {
	    Serial.print(" = ULTRA ToeR!!!! ");
    }
    else if (plante5 == 3)
    {
	    Serial.print(" = ToeR ");
    }
    else if (plante5 == 2)
    {
	    Serial.print(" = Normal ");
    }
    else if (plante5 == 1)
    {
	    Serial.print(" = Vaad ");
    }
    else if (plante5 == 0)
    {
	    Serial.print(" = Oversvoemmelse!!!! ");
    }

  Serial.print("\n Sensor aflaesning for soil6: ");
  Serial.print(soil6);
    
    if (plante6 == 4)
    {
	    Serial.print(" = ULTRA ToeR!!!! ");
    }
    else if (plante6 == 3)
    {
	    Serial.print(" = ToeR ");
    }
    else if (plante6 == 2)
    {
	    Serial.print(" = Normal ");
    }
    else if (plante6 == 1)
    {
	    Serial.print(" = Vaad ");
    }
    else if (plante6 == 0)
    {
	    Serial.print(" = Oversvoemmelse!!!! ");
    }

  Serial.print("\n");

  }

  void klokken()
  {
	getTime(3);
	Serial.print("\n Klokken er: \t");
	Serial.print(hours);
	Serial.print(":");
	Serial.print(minutes);
	Serial.print(":");
	Serial.print(seconds);
	Serial.print("\n");
  }

  void temper()
  {
  int temp;
	//temp = LM75_temperature();
	Serial.print("\n Rum temeperaturen er: \t");
	Serial.print(temp);
	Serial.print("\n");
  }



  void knapper()
  {
	 if(digitalRead(knap7) == LOW)
	 {
		 digitalWrite(led7, HIGH);
		 tid = tid + 3600;
	 }
	 else if(digitalRead(knap6) == LOW)
	 {
		 digitalWrite(led6, HIGH);
		 tid = tid - 3600;
	 }
	 else if(digitalRead(knap5) == LOW)
	 {
		 digitalWrite(led5, HIGH);
		 tid = tid + 60;
	 }
	 else if(digitalRead(knap4) == LOW)
	 {
		 digitalWrite(led4, HIGH);
		 tid = tid - 60;
	 }
	 else if(digitalRead(knap1) == LOW)
	 {
		 digitalWrite(led3, HIGH);
		 tid = tid + 1;
	 }
	 else if(digitalRead(knap0) == LOW)
	 {
		 digitalWrite(led2, HIGH);
		 tid = tid - 1;
	 }
	 else if(digitalRead(knap2) == LOW)
	 {
		 vandPumpe(!digitalRead(pumpe));
	 }
	 else
	 {
		 digitalWrite(led7, LOW);
		 digitalWrite(led6, LOW);
		 digitalWrite(led5, LOW);
		 digitalWrite(led4, LOW);
		 digitalWrite(led3, LOW);
		 digitalWrite(led2, LOW);
		 digitalWrite(led1, LOW);
	 }
  }


  int planteVudering(int plante)
  {
  unsigned int vudering;

	if(plante > 50)
	{
		vudering = 4;
	}
	else if (plante > 30)
	{
		vudering = 3;
	}
	else if (plante > 25)
	{
		vudering = 2;
	}
	else if (plante > 20)
	{
		vudering = 1;
	}
	else if (plante > 10)
	{
		vudering = 0;
	}

	return vudering;
  }

//
  //void i2c_init()
  //{
	  //// TWI prescaler = 1 (same as default)
	  //TWSR = 0;
	  //// LM75 clock has be to be lower than 400 kHz (according to LM75 data sheet)
	  //// We choose 2-wire clock ~ 50 kHz
	  //// The TWBR must be at least 10 in master mode (Mega32 data book)
	  //// SCL frequency = 3.6864 MHz / (16 + 2*TWBR*1), when prescaler = 1
	  //TWBR = 29;
  //}
//
  //void i2c_start()
  //{
	  //TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	  //while ((TWCR & (1<<TWINT)) == 0)
	  //{}
  //}
//
  //void i2c_write(unsigned char data)
  //{
	  //TWDR = data;
	  //TWCR = (1<<TWINT) | (1<<TWEN);
	  //while ((TWCR & (1<<TWINT)) == 0)
	  //{}
  //}
//
  //unsigned char i2c_read (unsigned char isLast)
  //{
	  //if (isLast == 0) //If we want to read more than 1 byte
	  //TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	  //else             //If we want to read only one byte
	  //TWCR = (1<<TWINT) | (1<<TWEN);
	  //while ((TWCR & (1<<TWINT)) == 0)
	  //{}
	  //return TWDR;
  //}
//
  //void i2c_stop()
  //{
	  //TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
  //}
//
  //#define LM75_BASE_ADDRESS 0b01001000
  //#define READ_MASK         0b00000001
//
  //// Reads the temperature register from specified sensor
  //// SensorAddress is between 0 and 7
  //int LM75_temperature()
  //{
	  //int temperature;
	  //char SensorAddress = 0;
	  //i2c_start();
	  //i2c_write(((LM75_BASE_ADDRESS + SensorAddress)<<1) | READ_MASK);
	  //// Read temperature high byte and ACK
	  //temperature = i2c_read(0);
	  //// Shift data to high byte
	  //temperature = temperature << 8 ;
	  //// Read temperature low byte and NACK
	  //// Merge to temperature variable
	  //temperature = temperature + i2c_read(1);
	  //i2c_stop();
	  //// Return right adjusted data (see LM75 data sheet)
	  //return (temperature>>7);
  //}
//
  //#define MMA8652_BASE_ADDRESS 0x1D
  //#define READ_MASK 0b00000001
  //#define X_MSB_ADR 0x01
  //#define Y_MSB_ADR 0x03
  //#define Z_MSB_ADR 0x05
  //#define CONTROL1_ADR 0x2A
  //#define CONTROL2_ADR 0x2B
//
  //void initAcc()
  //{
	  //// Initialize i2c hardware
	  //i2c_init();
	  //i2c_start();
	  //// Device write
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	  //// Write first register address
	  //i2c_write(CONTROL1_ADR);
	  //// Set ACTIVE bit
	  //i2c_write(0b00000001);
	  //i2c_stop();
  //}
//
  //int AccX()
  //{
	  //int x;
//
	  //i2c_start();
	  //// Device write
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	  //// Write first register address
	  //i2c_write(X_MSB_ADR);
	  //// Repeated start
	  //i2c_start();
	  //// Device read
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	  //// Read X high byte and ACK
	  //x = i2c_read(0);
	  //// Shift data to high byte
	  //x = x << 8 ;
	  //// Read X low byte and NACK
	  //// Merge to x variable
	  //x = x + i2c_read(1);
	  //i2c_stop();
	  //// Return right adjusted data (see MMA8652 data sheet)
	  //return (x>>4);
  //}
//
  //int AccY()
  //{
	  //int x;
//
	  //i2c_start();
	  //// Device write
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	  //// Write first register address
	  //i2c_write(Y_MSB_ADR);
	  //// Repeated start
	  //i2c_start();
	  //// Device read
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	  //// Read X high byte and ACK
	  //x = i2c_read(0);
	  //// Shift data to high byte
	  //x = x << 8 ;
	  //// Read X low byte and NACK
	  //// Merge to x variable
	  //x = x + i2c_read(1);
	  //i2c_stop();
	  //// Return right adjusted data (see MMA8652 data sheet)
	  //return (x>>4);
  //}
//
  //int AccZ()
  //{
	  //int x;
//
	  //i2c_start();
	  //// Device write
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1));
	  //// Write first register address
	  //i2c_write(Z_MSB_ADR);
	  //// Repeated start
	  //i2c_start();
	  //// Device read
	  //i2c_write(((MMA8652_BASE_ADDRESS)<<1) | READ_MASK);
	  //// Read X high byte and ACK
	  //x = i2c_read(0);
	  //// Shift data to high byte
	  //x = x << 8 ;
	  //// Read X low byte and NACK
	  //// Merge to x variable
	  //x = x + i2c_read(1);
	  //i2c_stop();
	  //// Return right adjusted data (see MMA8652 data sheet)
	  //return (x>>4);
  //}



//Til uret
ISR(TIMER1_OVF_vect)        // interrupt service routine
{
	TCNT1 = timer1_counter;   // preload timer
	
	digitalWrite(led0, !digitalRead(led0));

	if(tid > 86400)
	{
		tid = 0;

	}
	else
	{
		tid = tid + 1;
	}
}


