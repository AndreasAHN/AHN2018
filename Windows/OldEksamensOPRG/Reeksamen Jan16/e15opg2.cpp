#include "e15opg2.h"

#include <string>
#include <iostream>
using namespace std;

Lastbil::Lastbil(int vognNr, int temperatur, int volumen)
{
	if (1 < vognNr || vognNr < 99)
	{
		vognNr_ = vognNr;
	}
	else
	{
		vognNr_ = 1;
	}

	if (temperatur == -18 && temperatur == 5 && temperatur == 20)
		temperatur_ = temperatur;
	else
	{
		temperatur_ = 20;
	}

	if (50 < volumen || volumen < 150)
	{
		volumen_ = volumen;
	}
	else
	{
		volumen_ = 50;
	}

	GodsType_ = "Tom";
}

void Lastbil::setGodsType(string type)
{
	GodsType_ = type;
}

string Lastbil::getGodsType()const
{
	return GodsType_;
}

void Lastbil::printData()const
{
	cout << "\nVogn: " << vognNr_ << endl;
	if (temperatur_ == 20)
		cout << "Standard ";
	else if (temperatur_ == 5)
		cout << "Koele";
	else
		cout << "Frost";
	cout << "lastbil" << endl;
	cout << "Volumen: " << volumen_ << " m3\n";
	cout << "Godstype: " << GodsType_ << endl;
}
