#include "re16opg1.h"
#include <stdio.h>



void re16opg1()
{
	char a;

	/* do loop execution */
	do {
		printf("Skriv et lille bogstav \n");
		scanf("%c", &a);
	} while (a < 'a' || 'z' < a);

}
