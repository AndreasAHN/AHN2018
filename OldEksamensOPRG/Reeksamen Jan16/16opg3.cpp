#include "16opg3.h"
#include <string.h>
#include <stdio.h>
#include <cstdlib>

int e16opg3(char licensePlate[])
{
	int i;

	if (strlen(licensePlate) != 7)
		return 0;

	for (i = 0; i < 2; i++)
	{
		if (licensePlate[i] < 'A' || 'Z' < licensePlate[i])
			return 0;
	}
	for (i = 2; i < 7; i++)
	{
		if (licensePlate[i] < '0' || '9' < licensePlate[i])
			return 0;
	}
	return 1;
}
