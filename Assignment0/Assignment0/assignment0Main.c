/*********************************************************************************
** Program name: Assignment 0
** Author: Thomas Buteau
** Date: 4-9-17
** Description: This program converts inches to centimeters and vice versa.
**
*********************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*********************************************************************************
**								inToCM
** Description: Takes in a double representing inches as an argument then 
**				converts to centimeters and prints both. Does not change 
**				argument.
**
*********************************************************************************/
void inToCM(double foo)
{
	double bar = foo * 2.54;
	printf("%g inches is equal to %g centimeters.\n\n", foo, bar);
}


/*********************************************************************************
**								cmToIn
** Description: Takes in a double representing centimeters as an argument then
**				converts to inches and prints both. Does not change argument.
**
*********************************************************************************/
void cmToIn(double foo)
{
	double bar = foo * 0.3937;
	printf("%g centimeters is equal to %g inches.\n\n", foo, bar);
}



int main(int argc, char **argv)
{
	double a;
	double b;

	printf("Enter a length in inches to conver to centimeters.\n");
	scanf("%lf", &a);
	inToCM(a);

	printf("Enter a length in centimeters to conver to inches.\n");
	scanf("%lf", &b);
	cmToIn(b);

	return 0;
}