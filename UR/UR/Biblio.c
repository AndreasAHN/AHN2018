/*
 * Biblio.c
 *
 * Created: 08-11-2016 08:44:17
 *  Author: andre
 */ 

 #include <avr/io.h>
 #include "Biblio.h"

const int A = 13; //konstant for spole 1
const int B = 12; //konstant for spole 1
const int C = 11; //konstant for spole 2
const int D = 10; //konstant for spole 2

const int dips1 = 4; //konstant for spole 2
const int dips2 = 5; //konstant for spole 2
const int dips3 = 6; //konstant for spole 2
const int dips4 = 7; //konstant for spole 2


int d1 = 0;
int d2 = 0;
int d3 = 0;
int d4 = 0;

int dis[4] = {0, 0, 0, 0};

int x = 0;
int y = 0;
int z = 0;

int i = 0;




void digitalWrite(uint8_t pin, uint8_t val)
{
	uint8_t timer = digitalPinToTimer(pin);
	uint8_t bit = digitalPinToBitMask(pin);
	uint8_t port = digitalPinToPort(pin);
	volatile uint8_t *out;

	if (port == NOT_A_PIN) return;

	// If the pin that support PWM output, we need to turn it off
	// before doing a digital write.
	if (timer != NOT_ON_TIMER) turnOffPWM(timer);

	out = portOutputRegister(port);

	uint8_t oldSREG = SREG;
	cli();

	if (val == LOW) {
		*out &= ~bit;
		} else {
		*out |= bit;
	}

	SREG = oldSREG;
}

   void ur()
   {
	   if(dis[i] == 9)
	   {
		   e9();
	   }
	   else if(dis[i] == 8)
	   {
		   e8();
	   }
	   else if(dis[i] == 7)
	   {
		   e7();
	   }
	   else if(dis[i] == 6)
	   {
		   e6();
	   }
	   else if(dis[i] == 5)
	   {
		   e5();
	   }
	   else if(dis[i] == 4)
	   {
		   e4();
	   }
	   else if(dis[i] == 3)
	   {
		   e3();
	   }
	   else if(dis[i] == 2)
	   {
		   e2();
	   }
	   else if(dis[i] == 1)
	   {
		   e1();
	   }
	   else if(dis[i] == 0)
	   {
		   e0();
	   }
   }

   
   
   


   
   
   
   void e0()
   {
	   //0
	   digitalWrite(A,LOW);
	   digitalWrite(B,LOW);
	   digitalWrite(C,LOW);
	   digitalWrite(D,LOW);
	   delay(1);
   }

   void e1()
   {
	   //1
	   digitalWrite(A,LOW);
	   digitalWrite(B,LOW);
	   digitalWrite(C,LOW);
	   digitalWrite(D,HIGH);
	   delay(1);
   }


   void e2()
   {
	   //2
	   digitalWrite(A,LOW);
	   digitalWrite(B,LOW);
	   digitalWrite(C,HIGH);
	   digitalWrite(D,LOW);
	   delay(1);
   }

   void e3()
   {
	   //3
	   digitalWrite(A,LOW);
	   digitalWrite(B,LOW);
	   digitalWrite(C,HIGH);
	   digitalWrite(D,HIGH);
	   delay(1);
   }

   void e4()
   {
	   //4
	   digitalWrite(A,LOW);
	   digitalWrite(B,HIGH);
	   digitalWrite(C,LOW);
	   digitalWrite(D,LOW);
	   delay(1);
   }

   void e5()
   {
	   //5
	   digitalWrite(A,LOW);
	   digitalWrite(B,HIGH);
	   digitalWrite(C,LOW);
	   digitalWrite(D,HIGH);
	   delay(1);
   }

   void e6()
   {
	   //6
	   digitalWrite(A,LOW);
	   digitalWrite(B,HIGH);
	   digitalWrite(C,HIGH);
	   digitalWrite(D,LOW);
	   delay(1);
   }


   void e7()
   {
	   //7
	   digitalWrite(A,LOW);
	   digitalWrite(B,HIGH);
	   digitalWrite(C,HIGH);
	   digitalWrite(D,HIGH);
	   delay(1);
   }

   void e8()
   {
	   //8
	   digitalWrite(A,HIGH);
	   digitalWrite(B,LOW);
	   digitalWrite(C,LOW);
	   digitalWrite(D,LOW);
	   delay(1);
   }

   void e9()
   {
	   //9
	   digitalWrite(A,HIGH);
	   digitalWrite(B,LOW);
	   digitalWrite(C,LOW);
	   digitalWrite(D,HIGH);
	   delay(1);
   }