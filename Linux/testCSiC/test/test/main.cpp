
#import "/root/AHN2018/Linux/testCSiC/Cs_I_C/Cs_I_C/communikation.dll" raw_interfaces_only
using namespace communikation;

#include <stdio.h>

#include <iostream>


double Add(double op1, double op2)
{
                return communikation::communikation::Add(op1, op2);
}


int main (int argc, char *argv[])
{
	printf ("Hello world!\n");

	// Initialize COM.
   HRESULT hr = CoInitialize(NULL);



	int x,y;
	x = 3.45;
	y = 2.63;
	int s = Add(x,y);
	cout<<"x+y="<<s<<endl;


	return 0;
}

