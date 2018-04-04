#include "ReeksamenJan16.h"

#include <cstdlib>
#include <stdio.h>
#include "re16opg1.h"
#include "re16opg2.h"
#include "re16opg3.h"
#include "re16opg4.h"
#include "re16opg5.h"


void ReeksamenJan16()
{
	string name;
	int valgre16;
	int numberre16;
	int ire16;
	int roletteresultatre16;
	char tekstArray[] = "Husk altid at holde hovedet h\x9Bjt";

	system("cls");

	printf("Vaelg en af foelgende mulligheder:\n");
	printf("1: opg 1: Godtager lille bogstav\n");
	printf("2: opg 2: Lotteri\n");
	printf("3: opg 3: Tekst, find og erstat\n");
	printf("4: opg 4: Hotelroom\n");
	printf("5: opg 5: Hotel udbyder: Mislykkes\n");
	printf("0: Tilbage til forrige menu\n");
	printf("?: Exit:\n");

	scanf("%d", &valgre16);

	system("cls");

	printf("Stater foelgende valg '%d':\n", valgre16);

	if (valgre16 == 1) //Skriv et lille bogstav ( do while ) c# C#
	{
		re16opg1();
	}
	else if (valgre16 == 2) //Lotteri med random tal rand() c# C#
	{
		printf("Skriv et nummer mellem 0 og 36:\n");
		scanf("%d", &numberre16);

		for (ire16 = 0; ire16 < 10; ire16++)
		{
			roletteresultatre16 = roulette(numberre16);

			if (roletteresultatre16 == 1)
			{
				printf("Tillykke du har vundet 10.000 kr\n");
			}
			else
			{
				printf("Beklager, du har tabt igen\n");
			}
		}

	}
	else if (valgre16 == 3)  //tekst text i poiter array , find og erstat C# c# .
	{
		printf("%s\n", tekstArray);
		findOgErstat(tekstArray);
		printf("%s\n", tekstArray);
	}
	else if (valgre16 == 4)  //I denne opgave skulle der opstilles et Hotel med sotering af værelser c++ C++3
	{
		Hotelroom room1(10, 'D');
		Hotelroom room2(34, 'S');
		room1.setFree(false);
		room1.printRoom();
		room2.printRoom();
	}
	else if (valgre16 == 5)
	{
	//	printf("Skriv hotels navn:");
	//	cin >> navn;
	//	Hotel Hotel(name);
	//	Hotel printHotel();
	}
	else if (valgre16 == 0)		//Videre TAXA med konstrukter c++ C++
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
