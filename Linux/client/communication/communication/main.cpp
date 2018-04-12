#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protocol.h"

int buffer1 = 0; //Den modtaget int værdi fra server
string buffer2; //Den modtaget string fra server
bool msgSucces = false; //Fortæller om beskeden blev sendt
bool open = false; //Fortæller at forbindelsen til serveren er oprettet
char msgType = ' '; //Den forvented format af besked. S  er string, default int

string sendString; //Benyt denne variable til at ligge jeres besked i til afsending til server
int sendInt; //Benyt denne string til at ligge jeres besked i til afsending til server

int main(int argc, char *argv[])
{
	while(open == false)//Venter på der er oprettet forbindelse til server
	{
		open = serverOpen();
	}

	while(true)
	{
		//////////////// TIL PROTOCOL ////////////////////
	
		bool messageReady = tjekMessage();
		if(messageReady ==true)
		{
			switch(msgType) 
			{
			      case 'S' :
			         buffer2 = reciveMessageString();
			         msgType = ' '; 
			         break;
			      default :
			         buffer1 = reciveMessageInt();
		      }
		}

		//////////////// TIL PROTOCOL ////////////////////




		//Skriv jeres kode her!!! :P





		//////Benyt disse 2 funktioner efter behov til at sende. 
		/*
		while(msgSucces == false)
		{
			msgSucces = sendMessageString(sendString);
		}


		while(msgSucces == false)
		{
			msgSucces = sendMessageInt(sendInt);
		}
		*/







		//////////////// TIL PROTOCOL ////////////////////
		serverClose();
		//////////////// TIL PROTOCOL ////////////////////
	}

}
