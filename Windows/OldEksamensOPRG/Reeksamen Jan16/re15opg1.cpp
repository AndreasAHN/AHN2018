#include "re15opg1.h"
#include <stdio.h>

void re15opg1()
{
	int tal;

	do
	{
		printf("\nIndtast et helt tal > 1 : ");
		scanf("%d", &tal);

		if (tal < 1)
			printf("\nDu skal indtaste et tal > 1\n");

	} while (tal < 1);

	if (tal %2 == 0)
		printf("\n Tallet %d er et lige tal \n", tal);
	else
		printf("\n Tallet %d er et ulige tal \n", tal);
}
