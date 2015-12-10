/*
Create a C-program that reads the characters from the keyboard and shows them on screen 
(the inputted characters should only be displayed when the user hits 'enter', line by line). 
When ^A is entered, the program must end properly. Then the following message will appear:
“CTRL + A is a correct ending.”
Tip: getchar() reads and putchar() writes the type int. The value of ^A is 1.
*/
#include<stdio.h>

int main()
{
	char c; //declare c as a char
	printf("CTRL + A to end \n");
	while ((c=getchar()) != 1) //while ctrl a is not pressed, continue. 
		{
			//getchar is buffered so whatever the user types before pressing enter
			//will be placed in a buffer, then printed on the screen using putchar
			putchar(c);
		}
	printf("CTRL + A is a correct ending \n"); //if the loop is exited, that means that ctrl A was pressed
	return 0;
}