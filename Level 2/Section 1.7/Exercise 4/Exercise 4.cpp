/*
Create a C-program that has a function DayName()which can print the day of a given day-number. 
For example: 1 gives: Day 1 is a Sunday 7 gives: Day 7 is a Saturday. The day-name (1-7) should 
be written "hard-coded” into the program using an array of strings.
*/
#include<stdio.h>

char *DayName(int n) //functon returns a pointer.
{
	char *day[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	//the above is the declaration of array of pointers to store the strings for the days of the week.
	return day[n]; //the function returns the day number that the user requests
}

int main()
{
	int choice;
	printf("enter a number from 1 to 7 \n");
	scanf("%d", &choice);
	printf("%s \n", DayName(choice - 1)); //choice-1 because the array starts at 0.
	return 0;
}