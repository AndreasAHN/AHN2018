/**********************************************************
* "Switch.c"                                              *
* Implementation for "Mega2560 I/O Shield" SWITCH driver. *
* Henning Hargaard, 23/9 2015                             *
***********************************************************/
#include <avr/io.h>

// Klarg�r switch-porten
void initSwitchPort()
{
	DDRA = 0;
}

// L�ser alle switches samtidigt
unsigned char switchStatus()
{
	return ~PINA;
}

// Returnerer TRUE, hvis switchen med nummeret
// "switch_nr" er aktiveret - ellers returneres FALSE
unsigned char switchOn(unsigned char switch_nr)
{
	// Lokal variabel
	unsigned char mask;
		unsigned char result;
	// Vi skal kun lave noget, hvis led_nr < 8
	if (switch_nr <= 7)
	{
		// Dan maske p� basis af parameteren (led_nr)
		mask = 0b00000001 << switch_nr;
		// T�nd den aktuelle lysdiode (de andre �ndres ikke)
		result = mask & ~ PINA;
	}
	return result;
}