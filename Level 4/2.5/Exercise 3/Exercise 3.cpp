/*
let class manage memory
So instead of creating a C array with new, you can use an array class that handle memory for you.
create an array class for point objects
test array class
*/
#include"array.hpp"
#include<iostream>

int main() 
{
	Array a(5); //test size constructor
	//Array b; //test default constructor
	//Array b(a); //test copy constructor
	//below prints array for test
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] <<endl;
	}

	Array c;
	c = a; //test assignment operator
	c = c;
	for (int j = 0; j < c.size(); j++)
	{
		cout << c[j] <<endl;
	}
	point p1(2,3);
	cout << "2nd element of c is: " << c.getElement(2) << endl;
	c.setElement(2, p1);
	cout << "2nd element of c is now: " << c.getElement(2) << endl;

	cout << "9th non existent element of c is: " << c.getElement(9) << endl;
	//the above will just return the first element
	point p1;

	cout<< "3rd element of a is " << a[3] << endl;
	a[3] = p1;
	cout << "3rd element of a is now " << a[3] << endl;

	cout << "9th non existent element of a is: " << a[9] << endl;
	//the above will just return the first element


	return 0;
}
