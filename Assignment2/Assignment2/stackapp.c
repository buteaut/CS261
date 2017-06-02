/*
* CS261- Assignment 2 - stackapp.c
* Name: Thomas Butesu
* Date: 4-23-17
*/

/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */	
	DynArr *count = newDynArr(10);
	char temp;
	do
	{
		temp = nextChar(s);
		if ((temp == '(') || (temp == '[') || (temp == '{'))
		{
			pushDynArr(count, temp);
		}
		else if (temp == ')')
		{
			if (topDynArr(count) == '(')
			{
				popDynArr(count);
			}
			else
			{
				return 0;
			}
		}
		else if (temp == ']')
		{
			if (topDynArr(count) == '[')
			{
				popDynArr(count);
			}
			else
			{
				return 0;
			}
		}
		else if (temp == '}')
		{
			if (topDynArr(count) == '{')
			{
				popDynArr(count);
			}
			else
			{
				return 0;
			}
		}
	} while (temp != '\0');

	return isEmptyDynArr(count);
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}
