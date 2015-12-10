#include<stdio.h>
/*
	Create a C-program that counts how many times each of the numbers 0-4 have been typed. 
	Use a switch-case construction. Use default to count the number of other characters. 
	The input will be halted with ^Z (EOF). EOF means End-of-File and is defined in <stdio.h>. 
	Thus, the constant EOF can be used in a condition (test if EOF has been typed). 
	Print the amount of times a certain number has been typed. Name the program freq.c
	*/
int main() {
	char currentChar;
	int count0=0, count1=0, count2=0, count3=0, count4=0, countDefault=0; //initialize counts
	while (currentChar != EOF && currentChar != 4) {
		
		currentChar = getchar(); //currentChar gets the new char
		switch (currentChar){
		case '0':
			count0++;
			break;
		case '1':
			count1++;
			break;
		case '2':
			count2++;
			break;
		case '3':
			count3++;
			break;
		case '4':
			count4++;
			break;
		default:
			countDefault++;
		}
		
	} 
	printf("The number of times 0 appears: %d \n", count0);
	printf("The number of times 1 appears: %d \n", count1);
	printf("The number of times 2 appears: %d \n", count2);
	printf("The number of times 3 appears: %d \n", count3);
	printf("The number of times 4 appears: %d \n", count4);
	printf("The number of other characters (enters, spaces, other characters) appear: %d \n", countDefault-1);//subtract 1 because i think it counts the ctrlD as a character
	return 0;
}