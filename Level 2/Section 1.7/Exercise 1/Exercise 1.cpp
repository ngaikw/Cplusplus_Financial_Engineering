#include<stdio.h>
/*
Try to create a function Swap(). This function must exchange the value of two variables. 
For example: if i=123 and j=456, then i=456 and j=123 after the Swap() function has been called. 
The variables i and j are declared, initialised and printed in the function main(). This problem 
can be solved by using pointers as arguments for the Swap()function.
*/

void Swap(int* i, int* j)
{
	int holder_i = (*i); //set this to hold value that i points to
	int holder_j = (*j); //set this to hold the value that j points to
	(*i) = holder_j; //the contents of the address i holds is changed to value of j
	(*j) = holder_i; //the contents of the address j holds is changed to value of i
}

int main()
{
	int i, j;//declare
	i = 43;//initialize i and j
	j = 500;
	printf("i is %d \n", i);
	printf("j is %d \n", j);
	Swap(&i, &j); //pass the address of i and j into the swap function.
	printf("The new value for i is %d\n", i);
	printf("The new value for j is %d\n", j);
	return 0;
}