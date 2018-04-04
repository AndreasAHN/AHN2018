#include "ReeksamenJan15.h"

#include <cstdlib>
#include <stdio.h>
#include "re15opg1.h"
#include "re15opg2.h"

void ReeksamenJan15()
{
	int valg;
	int i;
	int tjek;

	system("cls");

	printf("Vaelg en af foelgende mulligheder:\n");
	printf("1: opg 1: Tal tjekker\n");
	printf("2: opg 2: Person klass\n");
	printf("3: opg 3:Klass Bank med Person: Mislykkes\n");
	printf("0: Tilbage til forrige menu\n");
	printf("?: Exit:\n");

	scanf("%d", &valg);

	system("cls");

	printf("Stater foelgende valg '%d':\n", valg);

	if (valg == 1) //Tester om et tal er lige eller ulige c# C#
	{
		re15opg1();
	}
	else if (valg == 2) //Husker Person oplysninger c++ C++
	{
		Person Person1("Andreas Hervert Nielsen", "2608941269");
		Person1.print();

		//1: Den kalder funktionen Person, her igennem kan man give den et
		//navn i en string og et person nummer.
			//1,1: Tjekker om personnummert kun er på 10 tal, ellers
			//lukker programmet.
			//1,2: Her tjekker den først om personnummer kun indholder tal
			//ellers lukker den programmet.
			//1,3: Her tjekker den og navnet kun indholder bogstaver,
			//ellers lukker den programmet.
			//1,4: Hvis 1,1, 1,2 og 1,3 er opfyldt, skriver den paramertre i privat
			//Under deres tilhørende parametre.
		//2: I klassen print. Her udskriver den navnet og personnummert til
		//terminalen, som stemmer overens med kaldet.
	}
	else if (valg == 3)  //Bankkonto c++ C++
	{
		/*void udskrivNegativeSaldoer(Bankkonto *arrayPtr, const int SIZE)
		{
			for (int taeller = 0; taeller<SIZE; taeller++)
				if (arrayPtr[taeller].getSaldo() < 0)
					arrayPtr[taeller].print();
		}*/
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
