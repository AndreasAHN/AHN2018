
#include "15opg1.h"
#include "e15opg2.h"
#include "Vintereksamen15.h"

#include <cstdlib>
#include <stdio.h>


void Vintereksamen15()
{
	int valg;
	int i;
	int tjek;

	system("cls");

	printf("Vaelg en af foelgende mulligheder:\n");
	printf("1: opg 1: Sum af tal og kommatal\n");
	printf("2: opg 2: Klass lasbil\n");
	printf("3: opg 3: \n");
	printf("0: Tilbage til forrige menu\n");
	printf("?: Exit:\n");

	scanf("%d", &valg);

	system("cls");

	printf("Stater foelgende valg '%d':\n", valg);

	if (valg == 1) //For loop skriver 5 tabellen mellem 5-50 c# C#
	{
		e15opg1();
	}
	else if (valg == 2) //Tabel maker, kan godtage alt mellem 0-10 c# C#
	{
		Lastbil scania(0, 0, 0);
		scania.printData();
		Lastbil volvo(13, 5, 144);
		volvo.setGodsType("Frugter");
		volvo.printData();
		Lastbil mercedes(51, -18, 75);
		mercedes.setGodsType("Is");
		mercedes.printData();
		cout << endl;
	}
	else if (valg == 3)  //Nummer plade tjkker af string c# C#
	{
		// Symbolet betyder, at der en relation af typen komposition 
		// mellem klasserne Godstransport og Lastbil.


		//Godstransport::Godstransport(int nr, int temp, int vol, string godsType,
		//	string fra, string til) :truck_(nr, temp, vol);
		//{
		//	truck_.setGodsType(godsType);
		//	A_ = fra;
		//	B_ = til;		//}		//		//int main()
		//{
		//	Godstransport nyTransport(55, 20, 80, "Juletraer", "Horsens", "Silkeborg");
		//	nyTransport.printTransport();
		//	cout << endl;
		//	return 0;
		//}
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
