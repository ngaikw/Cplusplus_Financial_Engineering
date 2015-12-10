/*
With an array of Points, all points are created with the default constructor.
When creating an array of pointers,
each element in the array must be created separately
but can be created with constructors other than the default constructor.
Thus creating an array of pointers is a two step process

• Create an array of Point pointers with 3 elements on the heap.
• Create for each element in the array a point on the heap.
• Iterate the array and print each point in the array.
• Iterate the array again and delete each point in the array.
• Delete the array itself.
Also make a drawing of the memory layout.

*/
#include "point.hpp"
#include<iostream>
using namespace std;

int main()
{
	const int size = 3; //set size of array
	point **p_Array = new point* [size]; //create an array of pointers
	//create a point on the heap for each element in the array:
	p_Array[0] = new point(3.0, 4.2);
	p_Array[1] = new point(2.0, 5.2);
	p_Array[2] = new point(1.5, 9);
	//loop to print out each point
	for (int i = 0; i < size; i++)
	{
		cout << (*p_Array[i]) << endl;
	}
	//loop to delete each point in the array
	for (int j = 0; j < size; j++) 
	{
		delete p_Array[j];
	}

	delete[] p_Array; //delete the array itself
	return 0;
}