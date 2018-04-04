#include "Musik.h"
#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>

//Tone biblotek
#define NOTE_E6  1319

#define NOTE_G6  1568

#define NOTE_GS6 1661

#define NOTE_A6  1760

#define NOTE_AS6 1865

#define NOTE_B6  1976

#define NOTE_C7  2093

#define NOTE_D7  2349

#define NOTE_E7  2637

#define NOTE_F7  2794

#define NOTE_G7  3136

#define NOTE_A7  3520


//Afspiller Mario Theme song
void musik()
{
	printf("Afspiller Mario Theme Song (15 sekunder)\n");
//Intro
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_C7, 1200);

	Wait(200);
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_G7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_G6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	printf("Afspiller Mario Theme Song (12 sekunder)\n");

//Mellem stykke 1
	Wait(200);
	PlayTone(NOTE_C7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_G6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_E6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_A6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_B6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_AS6, 1200);

	Wait(200);
	PlayTone(NOTE_A6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	printf("Afspiller Mario Theme Song (9 sekunder)\n");

//Mellem stykke 2
	Wait(200);
	PlayTone(NOTE_G6, 600);

	Wait(200);
	PlayTone(NOTE_E7, 600);

	Wait(200);
	PlayTone(NOTE_G7, 600);

	Wait(200);
	PlayTone(NOTE_A7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_F7, 1200);

	Wait(200);
	PlayTone(NOTE_G7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_C7, 1200);

	Wait(200);
	PlayTone(NOTE_D7, 1200);

	Wait(200);
	PlayTone(NOTE_B6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);


	printf("Afspiller Mario Theme Song (6 sekunder)\n");

//Mellem stykke 1
	Wait(200);
	PlayTone(NOTE_C7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_G6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_E6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_A6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_B6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_AS6, 1200);

	Wait(200);
	PlayTone(NOTE_A6, 1200);

	Wait(200);
	PlayTone(0, 1200);


	printf("Afspiller Mario Theme Song (3 sekunder)\n");

//Mellem stykke 2
	Wait(200);
	PlayTone(NOTE_G6, 600);

	Wait(200);
	PlayTone(NOTE_E7, 600);

	Wait(200);
	PlayTone(NOTE_G7, 600);

	Wait(200);
	PlayTone(NOTE_A7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_F7, 1200);

	Wait(200);
	PlayTone(NOTE_G7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_E7, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(NOTE_C7, 1200);

	Wait(200);
	PlayTone(NOTE_D7, 1200);

	Wait(200);
	PlayTone(NOTE_B6, 1200);

	Wait(200);
	PlayTone(0, 1200);

	Wait(200);
	PlayTone(0, 1200);

	printf("Afspiller Mario Theme Song (0 sekunder)\n");
}