#include <string.h>
using namespace std;
using byte = unsigned char;

//Call funktions
bool serverOpen();
void serverClose();

bool tjekMessage();

string reciveMessageString();
int reciveMessageInt();

bool sendMessageString(string msg);
bool sendMessageInt(int msg);


//Only for use in protocol
byte* recive();
bool send(byte*  msg);
byte*  convertMessageString(string msg);
byte*  convertMessageInt(int msg);

string decodeMessageString(byte*  msg);
int decodeMessageInt(byte*  msg);