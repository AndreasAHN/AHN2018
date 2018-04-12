#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <iknlib.h>
#include <string>

using namespace std;
using byte = unsigned char;

#define BUFSIZE  1000
#define PORT    17015
#define IP    "84.238.30.243"

//Own libs
#include "protocol.h"


bool serverOpen()
{


	return true;
}


void serverClose()
{


}

bool tjekMessage()
{

	return true;
}


byte*  recive()
{
	byte* bufRecive = new byte[3];


	return bufRecive;
}



bool send(byte*  msg)
{


	return true;
}


string reciveMessageString()
{
	byte*  msg = recive();

	string answer = decodeMessageString(msg);

	return answer;
}


int reciveMessageInt()
{
	byte*  msg = recive();

	int answer = decodeMessageInt(msg);

	return answer;
}

bool sendMessageString(string msg)
{
	byte*  answer = convertMessageString(msg);

	bool succes = send(answer);

	return succes;
}

bool sendMessageInt(int msg)
{
	byte*  answer = convertMessageInt(msg);

	bool succes = send(answer);

	return succes;
}


//Only for use in protocol
byte*  convertMessageString(string msg)
{
	byte* bufRecive = new byte[3];

	return bufRecive;
}

byte*  convertMessageInt(int msg)
{	
	byte* bufRecive = new byte[3];

	return bufRecive;
}

string decodeMessageString(byte*  msg)
{

	return "Hej med dig";
}

int decodeMessageInt(byte*  msg)
{


	return 42;
}