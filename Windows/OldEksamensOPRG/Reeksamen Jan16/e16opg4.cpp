#include "e16opg4.h"

#include <iostream>
using namespace std;

Taxa::Taxa(int vognNummer, int maxAntalKunder)
{
	setErDrift(false);
	setErLedig(true);

	vognNummer_ = (100 <= vognNummer && vognNummer <= 999) ? vognNummer : 100;
	maxAntalKunder_ = (4 <= maxAntalKunder && maxAntalKunder <= 8) ? maxAntalKunder : 4;
}

void Taxa::setErDrift(bool iDrift)
{
	if (iDrift == true)
		erIDrift_ = true;
	else
		erIDrift_ = false;
}

void Taxa::setErLedig(bool ledig)
{
	if (ledig == true)
		erLedig_ = true;
	else
		erLedig_ = false;
}

void Taxa::udskrivStatus() const
{
	cout << "Vogn" << vognNummer_ << endl;

	cout << "       " << maxAntalKunder_ << " pladser" << endl;

	if (erIDrift_ == false)
		cout << "       Ikke i drift" << endl;
	else
		cout << "       Er i drift" << endl;
	
	if (erLedig_ == false)
		cout << "       Optaget" << endl;
	else
		cout << "       Ledig" << endl;
}
