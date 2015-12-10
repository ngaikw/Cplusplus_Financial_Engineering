/* Exercise 1.8.1
print the contents of a struct called Article. Article has the following characteristics:
-article number
-quantity
-description (20 characters)
the test program must create an Article of which contents are assigned at initialization level

print article with Print() function. This function gets the address of the
structure as a parameter

tip: suppose p is the pointer to the structure. It will allow fields to be printed by
(*p).fieldname or p->fieldname
*/

#include<stdio.h>

void Print(struct Article* art); //declare function

struct Article //declare the struct here
{
	int number; //article number
	int quantity; //quantity
	char description[21]; //description max 20 characters
};

void Print(struct Article* art) //use a pointer to pass the structure to the print function
{
	printf("The article number is: %d, quantity is: %d, description: %s\n", art->number, art->quantity, art->description);
}


int main() 
{
	struct Article art1 = {3, 200, "news 4 u"}; //initialize the number, quantity, and description here
	Print(&art1); //call print function
	return 0;
}