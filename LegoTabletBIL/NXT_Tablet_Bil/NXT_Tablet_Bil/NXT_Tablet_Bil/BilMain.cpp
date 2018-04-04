#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>
#include <conio.h>
#include <cstdlib>
#include<iostream>+

#include <windows.h>



//Mine bibloteker:
#include "DriverNXT.h"

//Tone biblotek
#define NOTE_E6  1319

#define NOTE_E7  2637

// Hoved Program
int main()
{
	char key = 1;
	int state = 0;

	//Indlæser NXT Program til udfoersel:
	if (!Open())
	{
		printf("%s", "\nConnection failed\n");
		exit(1);
	}

	printf("%s", "\nConnection open\n");

	//Main kode her:

	drej_reset(); //Resetter drej

	while (true)
	{
		connection();

		//drej_position();

		//afstand();

		//if (key == 1)
		//{
		//	printf("Trykkede key: Ingen! \n", key);
		//}
		//else
		//{
		//	printf("Trykkede key: %d \n", key);
		//}
		
	//	key = 1; //Sørger for at sidste indtastning bliver slettet

	//	Wait(200);

	//	if(_kbhit()) //Modtager taste input
	//		key = _getch();  //_getch(); , getchar();  , 
	//	
	//	system("cls"); //Reseter CMD

	//	if (key == 115) //Forgear
	//	{
	//		state = 0;
	//	}
	//	else if (key == 119) //Bakgear
	//	{
	//		state = 1;
	//	}


	//	if (key == 120) //Stop
	//	{
	//		brems(1);
	//	}
	//	else if (key == 122) //Frigear
	//	{
	//		brems(0);
	//	}


	//	if (key == 100) //Drej højre
	//	{
	//		if (state == 0)
	//			drej(1);
	//		else if (state == 1)
	//			drej(2);
	//	}
	//	else if (key == 97) //Drej venstre
	//	{
	//		if (state == 0)
	//			drej(2);
	//		else if (state == 1)
	//			drej(1);
	//	}
	//	else //Reseter position drej til 0 stilling
	//	{
	//		drej(0);
	//	}


	//	if (key == 49) //Fremad 10%
	//	{
	//		if (state == 0)
	//		{
	//			frem(1);
	//		}
	//		else
	//		{
	//			bak(1);
	//		}
	//	}
	//	else if (key == 50) //Fremad 20%
	//	{
	//		if (state == 0)
	//		{
	//			frem(2);
	//		}
	//		else
	//		{
	//			bak(2);
	//		}
	//	}
	//	else if (key == 51) //Fremad 30%
	//	{
	//		if (state == 0)
	//		{
	//			frem(3);
	//		}
	//		else
	//		{
	//			bak(3);
	//		}
	//	}
	//	else if (key == 52) //Fremad 40%
	//	{
	//		if (state == 0)
	//		{
	//			frem(4);
	//		}
	//		else
	//		{
	//			bak(4);
	//		}
	//	}
	//	else if (key == 53) //Fremad 50%
	//	{
	//		if (state == 0)
	//		{
	//			frem(5);
	//		}
	//		else
	//		{
	//			bak(5);
	//		}
	//	}
	//	else if (key == 54) //Fremad 60%
	//	{
	//		if (state == 0)
	//		{
	//			frem(6);
	//		}
	//		else
	//		{
	//			bak(6);
	//		}
	//	}
	//	else if (key == 55) //Fremad 70%
	//	{
	//		if (state == 0)
	//		{
	//			frem(7);
	//		}
	//		else
	//		{
	//			bak(7);
	//		}
	//	}
	//	else if (key == 56) //Fremad 80%
	//	{
	//		if (state == 0)
	//		{
	//			frem(8);
	//		}
	//		else
	//		{
	//			bak(8);
	//		}
	//	}
	//	else if (key == 57) //Fremad 90%
	//	{
	//		if (state == 0)
	//		{
	//			frem(9);
	//		}
	//		else
	//		{
	//			bak(9);
	//		}
	//	}
	//	else if (key == 48) //Fremad 100%
	//	{
	//		if (state == 0)
	//		{
	//			frem(0);
	//		}
	//		else
	//		{
	//			bak(0);
	//		}
	//	}
	//	
	SetReverse(OUT_B, 100);
	}




	Close();
	system("PAUSE");
	return 0;
}
