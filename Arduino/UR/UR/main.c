/*
 * UR.c
 *
 * Created: 08-11-2016 08:37:51
 * Author : Andreas Hervert Nielsen
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "Biblio.h"
#include <pins_arduino.h>

int main(void)
{

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


DDRB = 0xFF; //Saetter pins til output

    /* Mit Program */
    while (1) 
    {
	start:
	while(x < 200)
	{
		digitalWrite(dips1,HIGH);
		//0
		e0();
		delay(1);
		digitalWrite(dips1,LOW);

		digitalWrite(dips2,HIGH);
		//1
		e1();
		digitalWrite(dips2,LOW);

		digitalWrite(dips3,HIGH);
		//2
		e2();
		digitalWrite(dips3,LOW);


		digitalWrite(dips4,HIGH);
		//3
		e3();
		digitalWrite(dips4,LOW);

		x++;
	}


	



	label:
	if(d3 >= 10)
	{
		goto start;
	}
	else if(dis[3] >= 10)
	{
		dis[4]++;
		dis[3] = 0;
		d3++;
	}
	else if(dis[2] >= 10)
	{
		dis[3]++;
		dis[2] = 0;
	}
	else if(dis[1] >= 10)
	{
		dis[2]++;
		dis[1] = 0;
	}
	else
	{
		
		while(z < 250)
		{
			digitalWrite(dips1,HIGH);
			i++;
			ur();
			//delay(1);
			digitalWrite(dips1,LOW);
			

			digitalWrite(dips2,HIGH);
			i++;
			ur();
			//   delay(1);
			digitalWrite(dips2,LOW);

			
			digitalWrite(dips3,HIGH);
			i++;
			ur();
			//      delay(1);
			digitalWrite(dips3,LOW);

			
			digitalWrite(dips4,HIGH);
			i++;
			ur();
			//     delay(1);
			digitalWrite(dips4,LOW);
			i = 0;
			z++;
		}
		z = 0;
		d1++;
		y++;
		dis[1]++;
    }
}

