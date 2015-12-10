#include<stdio.h>
int main() {
	/*Create a C-program that prints two columns on the screen with the temperature in degrees Celsius in the left column and 
	degrees Fahrenheit in the right column. Start with 0 degrees Celsius and proceed until 19 degrees Celsius. Take steps of 
	1 degree. Print degrees Fahrenheit with 1 position after the comma. Also print a header text. The result must be obtained 
	using a for construction!
	*/
	double startTemp = 0; //This can be changed according to what start temp you want
	double endTemp = 19; //This can be changed according to what end temp you want
	double stepSize = 1; //This can be changed according to step size
	double fahrenheitTemp;
	printf("celsius    fahrenheit\n");
	for (startTemp=0; startTemp<=19; startTemp++) {
		fahrenheitTemp = (9.0/5.0)*startTemp + 32.0;
		printf("%10.1f%11.1f\n", startTemp, fahrenheitTemp); 
	}
	return 0;
}