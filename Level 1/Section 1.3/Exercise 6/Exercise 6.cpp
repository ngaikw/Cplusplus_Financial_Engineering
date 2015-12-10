#include <stdio.h>
int main() {
	//Write a C-program that shifts any number two places to the right
	/* from wiki: Shifting left by n bits on a signed or unsigned binary number has
	the effect of multiplying it by 2n. Shifting right by n bits on an 
	unsigned binary number has the effect of dividing it by 2n (rounding towards 0).
	*/
	unsigned int toShift;
	printf("please enter an integer input\n");
	scanf("%ld", &toShift);
	//output the shifted result
	//also output whether logical or arithmetic shift is performed
	toShift = toShift >> 2;
	printf("The number shifted 2 places to the right is %ld \n", toShift);
	printf("A logical shift was performed\n");
	//logical shift will be performed for unsigned numbers (nonzero)
	signed int toShift2;
	printf("please enter another integer. Next we will perform an arithmetic shift \n");
	scanf("%ld", &toShift2);
	toShift2 = toShift2 >> 2;
	printf("The number shifted 2 places to the right is %ld \n", toShift2);
	printf("An arithmetic shift was performed");
	//and arithmetic shit for signed numbers(nozero and zero)
	return 0;
}