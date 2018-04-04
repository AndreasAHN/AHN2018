#pragma once
#include <iostream>
using namespace std;

class Hotel
{
public:
	Hotel(string name);
	void printHotel()const;

private:
	string name_;
	int rooms_;


};