#include <cstdlib>
#include <stdio.h>

#include "ReeksamenJan16.h"
#include "Vintereksamen16.h"
#include "ReeksamenJan15.h"
#include "Vintereksamen15.h"
#include "Vintereksamen14.h"
#include "Vintereksamen17.h"



int main()
{
	int valg;
	int a = 1;

	while (a == 1)
	{
		system("PAUSE");
		system("cls");

		printf("Vaelg en af foelgende mulligheder:\n");
		printf("1: ReeksamenJan16:\n");
		printf("2: Vintereksamen16:\n");
		printf("3: ReeksamenJan15:\n");
		printf("4: Vintereksamen15:\n");
		printf("5: Vintereksamen14:\n");
		printf("6: Vintereksamen17:\n");
		printf("?: Exit:\n");

		scanf_s("%d", &valg);

		printf("Stater foelgende valg '%d':\n", valg);

		if (valg == 1) //ReeksamenJan16
		{
			ReeksamenJan16();
		}
		else if (valg == 2) //Vintereksamen16
		{
			Vintereksamen16();
		}
		else if (valg == 3)  // ReeksamenJan15
		{
			ReeksamenJan15();
		}
		else if (valg == 4)  //Vintereksamen15
		{
			Vintereksamen15();
		}
		else if (valg == 5)  //Vintereksamen14
		{
			Vintereksamen14();
		}
		else if (valg == 6)  //Vintereksamen17
		{
			Vintereksamen17();
		}
		else if (valg == 5)
		{
			system("cls");
			printf("Du kunne bare ikke lade vaere med at proeve!!!!\n");
			printf("Starter programmet forfra for dig ;)\n");
		}
		else
		{
			system("cls");
			printf("Valget var ikke korrekt, stopper programmet!\n");
			a = 0;
		}
	}
	
	system("PAUSE");
	return (0);
}
