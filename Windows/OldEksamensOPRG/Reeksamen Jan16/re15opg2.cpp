#include "re15opg2.h"

#include <string>
#include <iostream>
using namespace std;
#include <ctype.h>


Person::Person(string navn, string nummer)
{
	if (nummer.length() != 10)
	{
		cout << "Fejl i data. Programmet lukkes ned." << endl;
		exit(1);
	}

	for ( int i = 0; i < 10 ; i++)
	{
		if (!isdigit(nummer[i]))
		{
			cout << "Fejl i data. Programmet lukkes ned." << endl;
			exit(1);
		}
	}

	for (int i = 0; navn[i] != '\0' ; i++)
	{
		if (!isalpha(navn[i]) && navn[i] != ' ')
		{
			cout << "Fejl i data. Programmet lukkes ned." << endl;
			exit(1);
		}
	}

	navn_ = navn;
	personnummer_ = nummer;
}

void Person::print(void)const
{
	cout << "\nNavn : " << navn_ << endl;
	cout << "Personnr: " << personnummer_ << endl;
}
