#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>
#include <iostream>
#include "FremStart.h"





int main()
{
	Lightsensor(1, true);

	if (!Open())
	{
		printf("%s", "\nConnection failed\n");
		exit(1);
	}
	printf("%s", "\nConnection open\n");

	int streg;

	Fremhalv();

	while (true)
	{
		if (streg <= 50)
		{

			Drejhøjre();
			Wait(100);


			Fremhalv();

			Drejvenstre();
			Wait(50);

		}


		streg = GetValue(1);
	}