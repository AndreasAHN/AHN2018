#include <QCoreApplication>

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

//#include "stdafx.h"
#include <metahost.h>
#include <atlbase.h>
#include <atlcom.h>

#define CLIBUFSIZE  50
#define SERVPORT    9002
#define SERVADDR    "10.0.0.1"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    HRESULT hr = CallClrMethod(
    L"ClassLibrary1.dll",  // name of DLL (can be fullpath)
    L"ClassLibrary1.Class1",  // name of managed type
    L"ManagedMethodCalledFromExtension", // name of static method
    L"some args",
    &dwResult);

    /*
    int client;
    struct sockaddr_in serv_addr;
    char buffer[CLIBUFSIZE] = {0};
    std::string request;

    // Validerer input
    if(argc < 2)
        error("Not enough arguments");
    request = argv[2];
    if(!(request == "u" || request == "U" || request == "l" || request == "L"))
        error("Invalid argument");

    // Indstiller server-sock_addr_in
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVPORT);

    // Saetter IP-adresse
    if (inet_aton(argv[1] , &serv_addr.sin_addr) == 0)
            error("ERROR on inet_aton()");


    // Opretter client socket
    client = socket(AF_INET, SOCK_DGRAM, 0);

    // Sender request til server
    if(sendto(client, request.c_str(), request.length(), 0, (struct sockaddr *) &serv_addr,
              (socklen_t)sizeof(serv_addr)) < 0)
        error("ERROR on sendto()");

    // Modtager svar fra server
    if(recv(client,buffer,sizeof(buffer),0) < 0)
        error("ERROR on recvfrom()");

    // Udskriver modtaget svar
    std::cout << "Received: " << buffer << std::endl;
*/
    return a.exec();
}

