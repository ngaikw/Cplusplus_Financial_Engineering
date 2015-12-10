#include<stdio.h>
//print 2 columns on the screen with temperature
//in fahrenheit (left) and celsius (right).
//Start with 0 degrees Fahrenheit and proceed until 300 degrees Fahrenheit. 
//Take steps of 20 degrees. Print degrees Celsius with 1 position behind the 
//comma (use “%10.1f” as format specifier). Also print a header text.
//Make the program maintenance insensitive, which means that the start- 
//and end-temperature and the step size must be easy to adjust.
//The result must be obtained using a while construction!
//Celsius = (5/9) * (Fahrenheit – 32)
int main() {
	double startTemp = 0; //This can be changed according to what start temp you want
	double endTemp = 300; //This can be changed according to what end temp you want
	double stepSize = 20; //This can be changed according to step size
	double celsiusTemp;
	printf("fahrenheit    celsius\n");
	while (startTemp <= 300){
		celsiusTemp = (5.0/9.0) * (startTemp - 32.0);
		printf("%10.1f%11.1f\n", startTemp, celsiusTemp); //10.1f tells you that you want it to cout to the 1st decimal place, 
		//and have a spacing of 10 characters. it is right aligned.
		startTemp+= stepSize;
	}


	return 0;
}