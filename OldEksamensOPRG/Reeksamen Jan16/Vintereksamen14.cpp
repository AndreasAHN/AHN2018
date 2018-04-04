#include "Vintereksamen14.h"
#include <cstdlib>
#include <stdio.h>

#include "e14opg1.h"
#include "e14opg2.h"


void Vintereksamen14()
{
	int valg;
	int i;
	int tjek;

	system("cls");

	printf("Vaelg en af foelgende mulligheder:\n");
	printf("1: opg 1: Er tallet større eller mindre end 10 c# C#\n");
	printf("2: opg 2: Lav en struktor for en cirkel\n");
	printf("3: opg 3: \n");
	printf("0: Tilbage til forrige menu\n");
	printf("?: Exit:\n");

	scanf("%d", &valg);

	system("cls");

	printf("Stater foelgende valg '%d':\n", valg);

	if (valg == 1) //Er tallet større eller mindre end 10 c# C#
	{
		e14opg1();
	}
	else if (valg == 2) //Lav en struktor for en cirkel 0-10 c# C#
	{
		e14opg2();
	}
	else if (valg == 3)  //
	{
		
	}
	else if (valg == 0)		//
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