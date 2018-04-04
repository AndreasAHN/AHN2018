#include "Vintereksamen17.h"

#include"e17opg1.h"
#include"e17opg2.h"
#include"e17opg3.h"

#include <cstdlib>
#include <stdio.h>

void Vintereksamen17()
{
	int valg;
	int i;
	int tjek;

	system("cls");

	printf("Vaelg en af foelgende mulligheder:\n");
	printf("1: opg 1: \n");
	printf("2: opg 2:  \n");
	printf("3: opg 3: \n");
	printf("4: opg 4:  \n");
	printf("5: opg 5: \n");
	printf("0: \n");
	printf("?: Exit:\n");

	scanf("%d", &valg);

	system("cls");

	printf("Stater foelgende valg '%d':\n", valg);

	if (valg == 1)
	{
		e17opg1();
	}
	else if (valg == 2)
	{
		
		
		stringToUnsignedInteger("a");

	}
	else if (valg == 3)
	{
//		e17opg3();
	}
	else if (valg == 4)
	{

	}
	else if (valg == 5)
	{
		//5A Symbolet betyder, at klassen Vognmand har en relation til klassen Taxa - i dette tilfælde af typen
		//komposition.


	}
	else if (valg == 0)
	{
		return;
	}
	else
	{
		system("cls");
		printf("Valget var ikke korrekt, stopper programmet!\n");
		exit(1);
	}
}