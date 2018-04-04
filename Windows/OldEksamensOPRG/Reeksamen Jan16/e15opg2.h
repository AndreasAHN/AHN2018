#pragma once
#include <string>
#include <iostream>
using namespace std;

class Lastbil
{
public:
	Lastbil(int vognNr, int temperatur, int volumen);

	void setGodsType(string type);
	string getGodsType()const;
	void printData()const;

private:
	int vognNr_;
	int temperatur_;
	int volumen_;
	string GodsType_;

};