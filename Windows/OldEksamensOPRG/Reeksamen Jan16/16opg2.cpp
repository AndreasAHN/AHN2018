#include "16opg2.h"

#include <stdio.h>

void e16opg2(int number)
{
	int i;

	if (number < 10)
	{
		printf("\n Her er %d - tabellen: \n", number);
		for (i = 1; i <= 10; i = i + 1)
		{
			printf("   %3d", i*number);
		}
	}
	else
	{
		printf("\n Tallet %d er ugyldigt \n", number);
	}
	
}
