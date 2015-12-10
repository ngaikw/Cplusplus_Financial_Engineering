#include<stdio.h>
/*
Extend the program of exercise 6 in such a way that the frequency of number 3 is shown in words. 
E.g.: Number three appears two times. Only print the frequency when it is smaller than three.
If the frequency is three or larger, then print: "The number three appears more than two times."
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
	printf("The number of times 4 appears: %d \n", count4);
	printf("The number of times other characters (enters, spaces, other characters) appear: %d \n", countDefault-1);//subtract 1 because i think it counts the ctrlD as a character
	if (count3 <= 3){
		switch(count3){
		case 0:
			printf("The number three does not appear.\n");
			break;
		case 1:
			printf("The number three appears one time.\n");
			break;
		case 2:
			printf("The number three appears two times.\n");
			break;
		case 3:
			printf("The number three appears three times.\n");
			break;
		}
	}
	else {
		printf("The number three occurs greater than three times.\n");
	}
	
	return 0;

}