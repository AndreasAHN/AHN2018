#include "16opg1.h"
#include "16opg2.h"
#include "16opg3.h"
#include "e16opg4.h"
#include "e16opg5.h"
#include "Vintereksamen16.h"

#include <cstdlib>
#include <stdio.h>


void Vintereksamen16()
{
		int valg;
		int i;
		int tjek;

		system("cls");

		printf("Vaelg en af foelgende mulligheder:\n");
		printf("1: opg 1: 5 tabellen\n");
		printf("2: opg 2: Tabel maker 1-10\n");
		printf("3: opg 3: Nummerplade tjekker\n");
		printf("4: opg 4: Taxa service\n");
		printf("5: opg 5: Taxa 2: Mislykkes at lave:\n");
		printf("0: Tilbage til forrige menu\n");
		printf("?: Exit:\n");

		scanf("%d", &valg);

		system("cls");

		printf("Stater foelgende valg '%d':\n", valg);

		if (valg == 1) //For loop skriver 5 tabellen mellem 5-50 c# C#
		{
			e16opg1();
		}
		else if (valg == 2) //Tabel maker, kan godtage alt mellem 0-10 c# C#
		{
			e16opg2(3);
			e16opg2(8);
			e16opg2(13);
		}
		else if (valg == 3)  //Nummer plade tjkker af string c# C#
		{
			for (i = 1; i <= 5; i = i + 1)
			{
				tjek = 0;

				if( i == 1 )
					tjek = e16opg3("BG73923");

				if(i==2)
					tjek = e16opg3("B173923");

				if(i==3)
					tjek = e16opg3("BG73X23");

				if(i==4)
					tjek = e16opg3("BG7392");

				if(i==5)
					tjek = e16opg3("BG739236");

				if(tjek == 1)
					printf(" Nummerplade nummer %d er gyldig! \n", i);
				else
					printf(" Nummerplade nummer %d er ugyldig! \n", i);
			}
		}
		else if (valg == 4)  //Taxa service c++ C++
		{
			Taxa Taxa147(147, 7);
			Taxa147.udskrivStatus();
		}
		else if (valg == 5)		//Videre TAXA med konstrukter c++ C++
		{
			//5A Symbolet betyder, at klassen Vognmand har en relation til klassen Taxa - i dette tilfælde af typen
			//komposition.


		}
		else if (valg == 0)		//Videre TAXA med konstrukter c++ C++
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
