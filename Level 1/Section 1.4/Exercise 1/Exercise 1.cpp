#include<stdio.h>
#include<ctype.h>
int main() {
	int countChar = 0, countWord = 0, countNewLine = 0;
	int currentChar= ' ', prevChar = ' ';
	while (currentChar != EOF && currentChar != 4) {
		
		currentChar = getchar(); //currentChar gets the new char

		if ( (prevChar==' ' || prevChar == '\n') && currentChar != ' ' && currentChar != 4 && currentChar != '\n' ) {
			countWord++; //assume that all words will be separated by a space or an enter
		}
		countChar++;
		if (currentChar == '\n') {
			countNewLine++;
		}
		prevChar = currentChar;	 //this assigns the last char that getchar obtained to prevChar
	} 
	printf("The number of words should be: %d \n", countWord);
	printf("The number of characters should be: %d \n", countChar-1); //subtract 1. I think this
	//counts an extra character at the end 
	printf("The number of lines should be: %d \n", countNewLine+1); //this is to count the first line
	return 0;
}