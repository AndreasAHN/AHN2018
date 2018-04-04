#include "re16opg2.h"
#include <stdio.h>
#include <time.h>
#include <cstdlib>



int roulette(int number)
{
	int Randomnumber = rand()%37;
	
	printf("Du fik foelgende nummer '%i':\n", Randomnumber);

	if (Randomnumber == number)
		return 1;
	else
		return 0;
}
