/* Exercise2
The following program reads a string with a 30 character maximum. 

Implement the Length() function. The function Length() must determine the length of the string. 
Give Length() the address of the array as argument. Note: your Length() function should be 
similar to the built-in strlen() function so your job is to mimic that function without using it.

control D is used instead of control Z. 
*/

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30

// String lenght declaration
int Length(char str[]);

int main()
{
char string[MAXLINE+1]; // Line of maxium 30 chars + \0
int c; // The input character
int i=0; // The counter
// Print intro text
printf("Type up to %d chars. Exit with ^D\n", MAXLINE);
// Get the characters
while ((c=getchar())!=4  && i<MAXLINE)
{
// Append entered character to string
string[i++]=(char)c;
}
string[i]='\0'; // String must be closed with \0
printf("string length is %d\n", Length(string));
return 0;
}

/* Implement the Length() function here */
int Length(char str[])
{
	int i = 0;
	while( str[i] != '\0')
	{
		i++;
	}
	return i;
}