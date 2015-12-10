/* Predict what will be printed on the screen */
#include <stdio.h>

#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line

// Create and initialse array
int a[]={0, 1, 2, 3, 4};

int main()
{
	int i;
	int* p;

	for (i=0; i<=4; i++) PRD(a[i]); // 1 prints: 01234
	/*This will print the array from the 0th position to the 4th position*/
	NL;
	
	for (p=&a[0]; p<=&a[4]; p++) PRD(*p); // 2 prints: 01234
	/*This for loop starts at address of 0th position of array and goes until 4th position.
	prints what is in that position of the array */
	NL;
	NL;
	
	for (p=&a[0], i=0; i<=4; i++) PRD(p[i]); // 3 prints: 01234
	/* p is assigned the address of the first element of a, a[0]. this will print p[0]
	then p[1], ...,p[4]
	*/
	NL;
	
	for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i)); // 4 prints: 024
	/*p points to first element in array. 
	loop continues until a+4, which is a[4]
	first will print a[0], then a[1+1], then a[2+2]*/
	NL;
	NL;
	
	for (p=a+4; p>=a; p--) PRD(*p); // 5 prints:43210
	/*starts at p[4] and prints values until p[0]*/
	NL;
	
	for (p=a+4, i=0; i<=4; i++) PRD(p[-i]); // 6  prints:43210
	/*starts at p[4]. prints values decrementing 1 in place each time.*/
	NL;
	
	for (p=a+4; p>=a; p--) PRD(a[p-a]); // 7 prints 43210
	/* starts at p= a + 4, then goes to a + 3, ..a + 0.
	prints a[4], a[3],..., a[0]*/
	NL;
	
	return 0;
}