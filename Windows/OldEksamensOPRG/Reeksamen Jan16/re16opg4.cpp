#include "re16opg4.h"
#include <iostream>
using namespace std;

Hotelroom::Hotelroom(int roomNumber, char type)
{
	setRoomNumber(roomNumber);
	setType(type);
	free_ = true;
}

void Hotelroom::setRoomNumber(int roomNumber)
{
	if (roomNumber > 0 || MAX_ROOMS < roomNumber)
	{
		roomNumber_ = roomNumber;
	}
	else
	{
		roomNumber_ = 0;
	}
}

int Hotelroom::getRoomNumber() const
{
	return roomNumber_;
}

void Hotelroom::setType(char type)
{
	if (type == 'd' || type == 'D')
	{
		type_ = 'D';
	}	
	else
	{
		type_ = 'S';
	}
	
}

char Hotelroom::getType() const
{
	return type_;
}

void Hotelroom::setFree(bool free)
{
	free_ = free;
}

bool Hotelroom::getFree() const
{
	return free_;
}

void Hotelroom::printRoom() const
{
	cout << "Vaerelse: " << roomNumber_ << endl;
	
	if (type_ == 'D')
	{
		cout << "       Dobbeltvaerelse "  << endl;
	}
	else
	{
		cout << "       Enkeltvaerelse " << endl;
	}


	if (free_ == false)
	{
		cout << "       Optaget" << endl;
	}
	else
	{
		cout << "       Ledigt" << endl;
	}
	

}
