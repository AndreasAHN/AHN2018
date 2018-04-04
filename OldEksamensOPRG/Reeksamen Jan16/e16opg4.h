#pragma once
#include "e16opg5.h"

class Taxa
{
public:
	Taxa(int vognNummer, int maxAntalKunder);

	void setErDrift(bool iDrift);
	void setErLedig(bool ledig);
	void udskrivStatus()const;

private:
	int vognNummer_;
	int maxAntalKunder_;
	bool erIDrift_;
	bool erLedig_;
};
