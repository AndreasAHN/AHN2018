#include "DriverNXT.h"
#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>


void frem(char fart)
{
	if (fart == 1)
	{
		SetForward(OUT_A, 10);
	}
	else if (fart == 2)
	{
		SetForward(OUT_A, 20);
	}
	else if (fart == 3)
	{
		SetForward(OUT_A, 30);
	}
	else if (fart == 4)
	{
		SetForward(OUT_A, 40);
	}
	else if (fart == 5)
	{
		SetForward(OUT_A, 50);
	}
	else if (fart == 6)
	{
		SetForward(OUT_A, 60);
	}
	else if (fart == 7)
	{
		SetForward(OUT_A, 70);
	}
	else if (fart == 8)
	{
		SetForward(OUT_A, 80);
	}
	else if (fart == 9)
	{
		SetForward(OUT_A, 90);
	}
	else if (fart == 0)
	{
		SetForward(OUT_A, 100);
	}
	else
	{
		printf("Frem vaerdi ikke gyldig");
	}
	return;
}

void bak(int fart)
{
	if (fart == 1)
	{
		SetReverse(OUT_A, 10);
	}
	else if (fart == 2)
	{
		SetReverse(OUT_A, 20);
	}
	else if (fart == 3)
	{
		SetReverse(OUT_A, 30);
	}
	else if (fart == 4)
	{
		SetReverse(OUT_A, 40);
	}
	else if (fart == 5)
	{
		SetReverse(OUT_A, 50);
	}
	else if (fart == 6)
	{
		SetReverse(OUT_A, 60);
	}
	else if (fart == 7)
	{
		SetReverse(OUT_A, 70);
	}
	else if (fart == 8)
	{
		SetReverse(OUT_A, 80);
	}
	else if (fart == 9)
	{
		SetReverse(OUT_A, 90);
	}
	else if (fart == 0)
	{
		SetReverse(OUT_A, 100);
	}
	else
	{
		printf("Bak vaerdi ikke gyldig");
	}
	return;
}

void brems(char stop)
{
		if (stop == 0) //Frigear
		{
			Stop(OUT_A, 0);
		}
		else if (stop == 1) //Brems
		{
			Stop(OUT_A, 1);
		}
		else
		{
			printf("Brems vaerdi ikke gyldig");
		}
		return;
}

void drej(int grader)
{
	int x;
	int y = 1;
	int z = 0;

	z = GetRotationCount(OUT_B);

	if (grader == 1) //Højre
	{
		if (80 == z) //Kan ikke dreje mere end 80 grader
		{

		}
		else
		{
			SetReverse(OUT_B, 50);
			Wait(10);
		}
			
	}
	else if (grader == 2) //Venstre
	{
		if (z == -80) //Kan ikke dreje mere end -80 grader
		{

		}
		else
		{
			SetForward(OUT_B, 50);
			Wait(10);
		}
	}
	else //Reset
	{
		/*while (y == 1)
		{
			x = GetRotationCount(OUT_B);
			if (x == 120)
			{
				y = 0;
			}
		}*/
		Stop(OUT_B, 1);
	}

	return;
}

void drej_position()
{
	int z;
	z = GetRotationCount(OUT_B);
	printf("Hjul position: %i \n", z);
}

void drej_reset()
{
	ResetRotationCount(OUT_B, 0);
}

void afstand()
{
	int afstand;

	SetSonar(IN_1);
	afstand = GetSonarValue(IN_1);

	printf("Afstand: %i cm \n", afstand);

	//if (afstand < 10)
	//	brems(1);
}

void dyt()
{
	PlayTone(250, 200);
}

int lydsensor()
{	
	int lyd;
	SetSound(IN_2);
	lyd = GetValue(IN_2);
	return(lyd);
}

void connection()
{
	if (!Open())
	{
		printf("%s", "Status: Connectet\n");
	}
	else
	{
		printf("%s", "Status: Disconnectet\n");
	}
}
