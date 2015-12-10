#include<stdio.h>
#include"Defs.h"
/*Create the two macros MAX2(x,y) and MAX3(x,y,z). These macros must return the maximum 
value of the given arguments. Let the macro MAX3 make use of the macro MAX2. Add these macros 
to the file “Defs.h”.
*/
int main()
{
	int x, y, z, max2, max3;
	x=3; //define x
	y=4; //define y
	z=5; //define z
	max2 = MAX2(x,y); //call macro max2
	printf("max2 call %d\n", max2);
	max3=MAX3(x,y,z); //call macro max3
	printf("max3 call %d\n", max3);
}