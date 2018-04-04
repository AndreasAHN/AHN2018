#include "FremStart.h"
#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>

//Defination x, front moter og y bag moter
int x = 0;
int y = 0;

void FremStart()
{
	while (x < 100, y < 100)
	{
		printf("Value of Motor FremStart: %d\n", x);
		Wait(5);
		SetForward(OUT_A, x);
		SetForward(OUT_B, y);
		x++;
		y++;
	}
}

void FremStop()
{
	while (x > 0, y > 0)
	{
		printf("Value of Motor FremStop: %d\n", x);
		Wait(5);
		SetForward(OUT_A, x);
		SetForward(OUT_B, y);
		x--;
		y--;
	}
}

void FremStopHalv()
{
	while (x > 50, y > 50)
	{
		printf("Value of Motor FremStopHalv: %d\n", x);
		Wait(5);
		SetForward(OUT_A, x);
		SetForward(OUT_B, y);
		x--;
		y--;
	}
}


void Fremhalv()
{

	while (x < 50, y < 50)
	{
		printf("Value of Motor FremHalv: %d\n", x);
		Wait(5);
		SetForward(OUT_A, x);
		SetForward(OUT_B, y);
		x++;
		y++;
	}

}

void Tilbagehalv()
{

	while (x < 50, y < 50)
	{
		printf("Value of Motor TilbageHalv: %d\n", x);
		Wait(5);
		SetReverse(OUT_A, x);
		SetReverse(OUT_B, y);
		x++;
		y++;
	}

}

void Drejhøjre()
{

	Stop(OUT_A, 0);

}

void Drejvenstre()
{
	Stop(OUT_B, 0);
}


void TilbageStart()
{
	while (x < 100, y < 100)
	{
		printf("Value of Motor TilbageStart: %d\n", x);
		Wait(5);
		SetReverse(OUT_A, x);
		SetReverse(OUT_B, y);
		x++;
		y++;
	}
}

void TilbageStop()
{
	while (x > 0, y > 0)
	{
		printf("Value of Motor TilbageStop: %d\n", x);
		Wait(5);
		SetReverse(OUT_A, x);
		SetReverse(OUT_B, y);
		x--;
		y--;
	}
}


