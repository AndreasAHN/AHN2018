#pragma once
const int MAX_ROOMS = 32;

class Hotelroom
{
public:
	Hotelroom(int roomNumber, char type);

	void setRoomNumber(int roomNumber);
	int getRoomNumber() const;
	void setType(char type);
	char getType() const;
	void setFree(bool free);
	bool getFree() const;
	void printRoom() const;

private:
	int roomNumber_;
	char type_;
	bool free_;
};



