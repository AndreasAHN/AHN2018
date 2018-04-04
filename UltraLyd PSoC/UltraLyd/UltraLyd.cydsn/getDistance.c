/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

/* [] END OF FILE */

#include "getDistance.h"


double getDistancex(double a, double b, double c)
{
	double B1 = -(b * b) + a * a + c * c;
	double B2 = 2 * a*c;
	double B3 = B1 / B2;
	double B = 90-((acos(B3)))*(360 / 2 / pi);
	double C = 90;

	double x1 = sin(B / 360 * 2 * pi) * a;
	double x2 = sin(C / 360 * 2 * pi);
	double x = x1 / x2;

	return x;
}

double getDistancey(double a, double b, double c)
{
	double B1 = -(b * b) + a * a + c * c;
	double B2 = 2 * a*c;
	double B3 = B1 / B2;
	double B = 90 - ((acos(B3)))*(360 / 2 / pi);
	double C = 90;

	double A = 180 - (B + C);
	double y1 = sin(A / 360 * 2 * pi) * a;
	double y2 = sin(C / 360 * 2 * pi);
	double y = y1 / y2;

	return y;
}