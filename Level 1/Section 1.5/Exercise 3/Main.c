#include<stdio.h>
#include"print.h"
int main() {
	float i; 
	printf("enter the digit to multiply by 2: \n");
	scanf("%f", &i);

	printFunc(i);
	return 0;
}