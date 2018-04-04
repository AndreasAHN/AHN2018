#include "15opg1.h"
#include <stdio.h>

void e15opg1()
{
	double tal[5] = { 0 };
	int i;
	double sum = 0;

	for (i = 0; i < 5; i++)
	{
		printf("Indtast det %d tal:", i + 1);
		scanf("%lf", &tal[i]);
		sum += tal[i];
	}
	printf("Summen %lf tal:", sum);
}
