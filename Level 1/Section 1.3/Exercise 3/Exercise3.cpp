#include <stdio.h>
int main()
{
	int x;
	x=-3+4*5-6; // x=11
	printf("x=%d\n", x); // This will print 11
	x=3+4%5-6; // x=1
	printf("x=%d\n", x); // This will print 1
	x=-3*4%-6/5; // x=0/5
	printf("x=%d\n", x); //This will print 0
	x=(7+6)%5/2; //x=3/2
	printf("x=%d\n", x); //This will print 1
	return 0;
}