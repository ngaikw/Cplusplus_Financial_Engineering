/*
Until now, we created objects on the stack. 
The stack is limited in size thus when creating 
many objects, the stack will overflow. Also arrays
created on the stack can only have a fixed size
determined at compile time. To overcome these 
problems we have to create objects on the heap 
using new.

1.create Point objects on the heap with new using the default constructor, 
constructor with coordinates and the copy constructor and assign it to pointer (Point*) variables. 
The pointer must first be dereferenced when passing it to the copy constructor. (Point* p2=new Point(*p1))

call the Distance() function on the pointers and try to send the Point pointers to cout. 
You need to dereference the pointer when passing it as argument. Don’t forget to delete the 
object created with new. Test the main program.

2.create an array of points. First ask the user for the size of the array and read it using cin. 
Then try to create an array on the stack using the entered size. You will see a compiler error. 
Arrays on the stack must have the size set at compile time. 
Now create the array on the heap using new.
Can you use other constructors than the default constructor for the objects created in the array? 
Don’t forget to delete the array after use. Don’t forget the square brackets when deleting arrays!
*/

#include "point.hpp"
#include<iostream>
using namespace std;

int main()
{
	//part 1:
	point* p1; //pointer to object
	point* p2;
	point* p3;
	p1 = new point; //create point object on the heap using default constructor
	p2 = new point(2, 3); //create point using constructor w coordinates
	p3 = new point(*p1); //create point using copy constructor

	cout << (*p1).distance(*p2) << endl;;
	cout << "p1: " << *p1 << endl;
	cout << "p2: " << *p2 << endl;
	cout << "p3: " << *p3 << endl;
	
	delete p1;
	delete p2;
	delete p3;

	//part 2
	int n;
	cout << "enter the size of the array" << endl;
	cin >> n;
	// point p_Array[n]; //this produces a compile error
	point* p_Array = new point[n];
	for (int i = 0; i < n; i++) //
	{
		p_Array[i].X(5.6); //make x coordinate of the points in the array = 5.6
		p_Array[i].Y(6.6); //make y coordinates of points in the array = 6.6
	}
	
	delete [] p_Array;


	return 0;
}