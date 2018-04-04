#pragma once

#include <iostream>
using namespace std;

class Person
{
public:
	Person(string navn, string nummer);

	void print(void)const;

private:
	string navn_;
	string personnummer_;

};
