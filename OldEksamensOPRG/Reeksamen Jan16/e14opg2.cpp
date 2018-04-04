#include "e14opg2.h"
#include <stdio.h>

struct Circle
{
	int x_;
	int y_;
	float radius_;
};

void e14opg2()
{
	struct Circle c1, c2 = { 2, 4, 7.3 };
	int x, y;
	float radius;

	printf("Indtast centrum koordinater x og y samt radius for en cirkel.\nx: ");
	scanf("%d", &x);
	printf("y: ");
	scanf("%d", &y);
	printf("Radius: ");
	scanf("%f", &radius);
	c1.x_ = x;
	c1.y_ = y;
	c1.radius_ = radius;
}
