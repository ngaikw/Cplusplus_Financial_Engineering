#include<stdio.h>
int main() {
	/* multiplies number by a factor 2 to the power n
	number and n are variables inputted at start of program
	clue: 1 shift to left is the same as *2
	2 shifts to left same as *4 (2^2)
	3 shifts to left same as *8 (2^3) */
	int num, n;
	printf("Please enter a number (integer)\n");
	scanf("%d", &num);
	printf("I will multiply this number by a factor 2 to the power n. Enter n (integer) \n");
	scanf("%d", &n);
	printf("%d", num << n, "\n");
	return 0;
}