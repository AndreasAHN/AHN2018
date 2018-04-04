#pragma comment( lib, "NXT++.lib" )
#include <NXT++.h>


int main()
{
	if (!Open())
	{
		printf("%s", "\nConnection failed\n");
		exit(1);
	}

	printf("%s", "\nConnection open\n");


	// Skriv din kode her


	Close();

	return 0;
}