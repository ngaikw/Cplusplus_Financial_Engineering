//same as exercise 1 but use switch statement
//i am confused by this one
#include<stdio.h>
int main() {
	int countChar = 0, countWord = 0, countNewLine = 0;
	int currentChar= ' ', prevChar = ' ';
	while (currentChar != EOF && currentChar != 4) {
		currentChar = getchar(); //currentChar gets the new char
		switch (currentChar){
		case '\n':
			countNewLine++;
			switch(prevChar){ //if the previous char was a character, this means that you have a new word
			case' ': 
				break;
			case '\n':
				break;
			default:
				countWord++;
				break;
			}
			prevChar = currentChar;
		case ' ':
			switch(prevChar) {//you have a new word if the previous char was a character
			case ' ':
				break;
			case '\n':
				break;
			default: //when the previous char is a character
				countWord++;
				break;
			}
			prevChar=currentChar;
		default: //the default case is for when any character is typed
			countChar++;
			prevChar=currentChar;
			break;
		}
	}
	printf("The number of words should be: %d \n", countWord);
	printf("The number of characters should be: %d \n", countChar-1); //subtract 1. I think this
	//counts an extra character at the end 
	printf("The number of lines should be: %d \n", countNewLine+1); //this is to count the first line
	return 0;
}