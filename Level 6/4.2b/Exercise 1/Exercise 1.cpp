/*
Exercise 2: Static variable for array default size
static variables are shared between all instances of a class. they behave slightly
differently with templates.

test with static variable in array class tha tindicates default array size when using the default constructor.
*/
#include <iostream>		
#include <string>
using namespace std;
#include"array.cpp"


int main() {
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;

	cout << intArray1.defaultSize() << endl;
	cout<<intArray2.defaultSize()<<endl;
	cout<<doubleArray.defaultSize()<<endl;

	intArray1.defaultSize(15);

	cout<<intArray1.defaultSize()<<endl;
	cout<<intArray2.defaultSize()<<endl;
	cout<<doubleArray.defaultSize()<<endl;
	return 0;
}