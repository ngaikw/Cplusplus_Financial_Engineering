#include<stdio.h>
/*
Write a C-program that calls a function minus(). 
This function receives two arguments and returns the difference 
(regular subtraction, not absolute). This difference should be printed on screen.
*/
double minus(double a, double b){
	double ans;
	ans=a-b;
	return ans;
}
int main() {
	double a, b;
	printf("I will subtract two numbers, a-b. Enter a \n");
	scanf("%lf", &a);
	printf("Enter b \n");
	scanf("%lf", &b);
	printf("result is: %lf \n", minus(a,b));
	return 0;
	
}