#include "e14opg1,1.h"
#include <stdio.h>

double bigNumber(double array[], int SIZE)
{
	for (int i = 0; i <= SIZE; i++)
	{
		if (array[i] > 10)
		{
			printf("\n Tallet %f er stoerre end 10 \n", array[i]);
			return array[i];
		}
		else
		{
			printf("\n Tallet %f er mindre end 10 \n", array[i]);
		}
	}
	return 0.0;
}
