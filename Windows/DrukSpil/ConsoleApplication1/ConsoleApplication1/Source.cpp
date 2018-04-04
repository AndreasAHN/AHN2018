#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include <string>

const int antal = 9;
const int drinks = 16;
using namespace std;


int main()
{
	srand(time(0));
	string names[antal] = {
		"Andreas Hervert nielsen", "Per Jakobsen", "Rikke Wolf Pedersen", "Camilla Gottlieb Andersen", "Caroline Lykkegaard", "Ida Isager Fugelsang", "Jonas Soeby", "Asbjoern Bratsbjerg" ,"Faelles"};

	string drik[drinks] = {"Lav 5 armboejninger og drik en slurk mellem hver armboejning", 
		"drik 3 slurke",  "udfordr en person, eks. tommelfinger leg", "drik' 1 slurk", "drik' 2 slurke", 
		"Udfordre sidemandende til Danmarks geografi", 
		"Udfordre en til at stave et vilkaarligt 6 bogstavs ord bagfraadrtfrter,", 
		"Lav et anagram udfra dit navn eller den der sidder til hoejre for digs navn", 
		"tommelfinger regel, taber drikker 3 slurke, valgfri tidspunkt", "vandfald", 
		"give en person et  nyt oegenavn", "skal tage 3 armbøjninger", "& Andreas skal %28de Asbjoerns koebenhavnerstang"
		, "sig fem flade floedeboller paa et fladt floedebollefad fem gange efter hinanden hurtigt, straf 4 slurke",
		"skal kigge på sit glas hvis det er tomt hent noget vand",
	"er en hjort, som skal drikke en HEL øl!!!!"};

	char tast;
	int dahm = 0;
	int dahm2 = 0;
	int holdStyr = 0;
	int holdstyr2 = 0;

	holdStyr = ((time(0) % 5) + 1);
	holdstyr2 = holdStyr;


	while (true)
	{
		string printString;
		
		if (time(0) % 61 == 0)
		{
			system("cls");
			dahm = rand() % antal;
			for (size_t i = 0; i < (rand() % 10); i++)
			{

			}
			dahm2 = (rand() % drinks);
			cout << names[dahm] << " ";
			//if (names[dahm] == names[antal-1])
			//{
			//	if (drik[dahm2] == drik[1])
			//	{
			//		cout << "Aaaahhhhhhhhhhhh nej" << endl; //Kun åhhhh nej når at det er bund
			//		for (size_t i = 0; i < 20; i++)
			//		{
			//			Beep(1568, 100);
			//			Beep(0, 50);
			//		}
			//	}
			//	else
			//	{
			//		cout << " skaal" << endl << "JHAAAAAAAHHH!!!!!" << endl; //Kun åhhhh nej når at det er bund
			//		for (size_t i = 0; i < 20; i++)
			//		{
			//			Beep(1569, 100);
			//			Beep(0, 50);
			//		}
			//	}
			//}
			//else
			//{
				cout << "skal " << drik[rand() % drinks];
			//}
			Beep(1568, 200);
		}

		holdStyr = ((time(0) % 61));

		if ((holdStyr != holdstyr2) && holdStyr >= 31 && holdStyr > 0)
		{
			system("cls");
			cout << 61-((time(0) % 61)) << endl;
			holdstyr2 = holdStyr;
		}

	}

	return 0;
}