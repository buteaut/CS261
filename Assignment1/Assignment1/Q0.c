/* CS261- Assignment 1 - Q. 0*/
/* Name: Thomas Butesu
 * Date: 4-16-17
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	printf("%d \n", *iptr);
     /*Print the address pointed to by iptr*/
	printf("%x \n", iptr);
     /*Print the address of iptr itself*/
	printf("%x \n", &iptr);
}

int main(){
    
    /*declare an integer x*/
	int x = 42;
    /*print the address of x*/
	printf("%x \n", &x);
    /*Call fooA() with the address of x*/
	fooA(&x);
    /*print the value of x*/
	printf("%d \n", x);
    return 0;
}
