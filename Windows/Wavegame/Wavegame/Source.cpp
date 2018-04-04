#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <string>
#include <new> 
#include "players.h"



using namespace std;


void display();
int players = 1;
string player1 = "Unknow";
string player2 = "Unknow";
string player3 = "Unknow";
string player4 = "Unknow";
unsigned int player[4][20][20];
unsigned int disp[20][20];
unsigned int counter, win1, win2, win3, win4 = 0;
int player1timer = 0;
int player2timer = 0;
int player3timer = 0;
int player4timer = 0;

int main()
{
	int valg;
	int a = 1;

	while (a == 1)
	{
		system("PAUSE");
		system("cls");

		printf("Vaelg en af foelgende mulligheder:\n");
		printf("1: Start:\n");
		printf("2: Reset:\n");
		printf("3: Settings:\n");
		printf("?: Exit:\n");

		scanf_s("%d", &valg);

		printf("Stater foelgende valg '%d':\n", valg);

		if (valg == 1) //Start
		{
			int f = 0;
			player1timer = 0;
			while (f <= 99)
			{
				for (int y = 19; y >= 0; y = y - 1)
				{
					for (int x = 0; x <= 19; x = x + 1)
					{
						disp[x][y] = rand() % 10;
					}
				}


				int answer = 0;


				int time1 = clock();

				int player1answer = player1algo(disp);

				int time2 = clock();
				player1timer = time2 - time1;


				time1 = clock();

				int player2answer = player2algo(disp);

				time2 = clock();
				player2timer = time2 - time1;


				time1 = clock();

				int player3answer = player3algo(disp);

				time2 = clock();
				player3timer = time2 - time1;

				time1 = clock();

				int player4answer = player4algo(disp);

				time2 = clock();
				player4timer = time2 - time1;


				if (player1timer <= player2timer || player1timer <= player3timer || player1timer <= player4timer)
				{
					if (player1answer == answer)
					{
						win1++;
					}
					else
					{
						printf("\n Player 1s code, doesn't work");
							system("PAUSE");
					}
				}
				else if (player2timer <= player1timer || player2timer <= player3timer || player2timer <= player4timer)
				{
					if (player2answer == answer)
					{
						win2++;
					}
					else
					{
						printf("\n Player 2s code, doesn't work");
							system("PAUSE");
					}
				}
				else if (player3timer <= player2timer || player3timer <= player1timer || player3timer <= player4timer)
				{
					if (player3answer == answer)
					{
						win3++;
					}
					else
					{
						printf("\n Player 3s code, doesn't work");
							system("PAUSE");
					}
				}
				else
				{
					if (player4answer == answer)
					{
						win4++;
					}
					else
					{
						printf("\n Player 4s code, doesn't work");
						system("PAUSE");
					}
				}

				display();
				f++;

				
			}


		}
		else if (valg == 2) //Reset
		{
			for (int c = 0; c <= 19; c = c + 1)
			{
				disp[c][c] = 0;
			}
			counter = 0;
		}
		else if (valg == 3)  // Settings
		{
			system("cls");

			printf("Vaelg en af foelgende mulligheder:\n");
			printf("\n 1: player 1 navn:\n");
			cout << player1;
			printf("\n 2: player 2 navn:\n");
			cout << player2;
			printf("\n 3: player 3 navn:\n");
			cout << player3;
			printf("\n 4: player 4 navn:\n");
			cout << player4;
			printf("\n 5: Antal spiller, som skal spille med:\n");
			cout << players;
			printf("\n ?: Exit:\n");
			
			scanf_s("%d", &valg);

			printf("Stater foelgende valg '%d':\n", valg);

			if(valg <= 4)
			printf("Skriv player '%d' nye navn:\n", valg);
			
			if (valg == 1) //player 1
			{
				cin >> player1;
				cout << "Hello, " << player1 << "!\n";
			}
			else if (valg == 2) //player 2
			{
				cin >> player2;
				cout << "Hello, " << player2 << "!\n";
			}
			else if (valg == 3)  //player 3
			{
				cin >> player3;
				cout << "Hello, " << player2 << "!\n";
			}
			else if (valg == 4)//player 4
			{
				cin >> player4;
				cout << "Hello, " << player2 << "!\n";
			}
			else if (valg == 5) //Antal spillere der er med:
			{
				printf("\n Hvor mange spiller er med? \n");
				scanf_s("%d", &players);
			}
			else
			{
				printf("\n Ugyldigt valg, tilbage til hovedemenu \n");
			}


		}
		else if (valg == 4)
		{
			system("cls");
			printf("Du kunne bare ikke lade vaere med at proeve!!!!\n");
			printf("Starter programmet forfra for dig ;)\n");
		}
		else
		{
			system("cls");
			printf("Valget var ikke korrekt, stopper programmet!\n");
			a = 0;
		}
	}

	return (0);
}




void display()
{
	system("cls");

	disp[0][19] = 5;
	disp[19][0] = 6;

		for (int y = 19; y >= 0; y = y - 1)
		{
			for (int x = 0; x <= 19; x = x + 1)
			{
				printf("-'%d'-", disp[x][y]);
			}
			printf("\n");
		}

		counter++;
		printf("\n Counter: %d ", counter);
		cout << "\t Player 1: " << player1;
		cout << "\t\t Player 2: " << player2;
		cout << "\t\t Player 3: " << player3;
		cout << "\t Player 4: " << player4 << endl;
		printf("\n Points: ");
		printf("\t Player 1: %d ", win1);
		printf("\t \t Player 2: %d ", win2);
		printf("\t \t Player 3: %d ", win3);
		printf("\t \t Player 4: %d \n", win4);

		Sleep(5);
}



