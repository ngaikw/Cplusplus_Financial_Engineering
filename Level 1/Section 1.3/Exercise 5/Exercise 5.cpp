#include<stdio.h>
int main() {
	int n=5;
	printf("n = %d\n", --n); //this will print out 4
	n = 5;
	printf("n = %d\n", n-- ); //this will still print out 5 because n is not decremented before printing
	printf("n = %d\n", n); //but now that the -- was carried out, we can print n and see that n is decremented
	return 0;
}