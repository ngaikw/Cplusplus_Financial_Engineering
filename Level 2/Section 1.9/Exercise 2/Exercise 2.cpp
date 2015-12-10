/*
Alter the last program of exercise 1 in such a way that the output doesn’t go to the screen but is written to a file. 
The file to write to must be specified by the user.
*/
#include<stdio.h>

int main()
{
	FILE* fp;
	char file_name[20];
	char c; //declare c as a char
	printf("enter the file name followed by .txt, file name cannot be more \nthan 20 characters including '.txt' e.g. file1.txt \n");
	scanf("%s", file_name);
	fp = fopen(file_name, "w");

	printf("CTRL + A to end \n");
	fflush(stdin); //this is included so there is no extra enter placed in the buffer in the beginning 
	while ((c=getchar()) != 1) //while ctrl a is not pressed, continue. 
		{
			//getchar is buffered so whatever the user types before pressing enter
			//will be placed in a buffer, then printed in the file using fputc
			fputc(c, fp);
			
		}
	printf("CTRL + A is a correct ending \n"); //if the loop is exited, that means that ctrl A was pressed
	
	fclose(fp);
	return 0;
}