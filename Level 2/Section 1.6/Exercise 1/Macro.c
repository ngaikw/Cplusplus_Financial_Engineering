#include<stdio.h>
#include"Defs.h"


/*Write a C-program that contains two print macro calls. The first prints the variable a, 
the second prints the variables a and b. Printing happens by the use of the PRINT1 and
 PRINT2 macros that accept arguments. These macros must be defined in an include-file. 
The variables a and b gets their value in the function main(). Name the program “Macro.c” 
and the include-file “Defs.h”. Don’t forget to implement the mechanism to avoid multiple 
inclusion of the header file.
*/

int main() 
{
	int a,b;
	a=5;//assign value to variable a
	b=7;//assign value to variable b
	PRINT1(a);//macro call to print a
	PRINT2(a, b); //macro call to print a and b

	return 0;
}