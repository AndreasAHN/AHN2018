#include "e17opg1.h"

#include <stdio.h>

void e17opg1()
{
	double number , bigArray[300] = { 0 };
	int i;

	printf("Indtast et decimaltal:");
	scanf("%lf", &number);

	for (i = 0; i <= 299; i++)
	{
		bigArray[i] = number;
		printf("  %.2f  ", bigArray[i]);
	}
}
