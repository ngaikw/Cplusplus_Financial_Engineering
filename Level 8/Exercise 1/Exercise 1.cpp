/*
Exercise 1: Smart Pointers
The boost::shared_ptr<T> class stores a pointer and will delete the object automatically when 
nobody is referencing the object anymore.
we can create an array with boost::shared_ptr<Shape> and the deletion of the shapes will 
be done automatically. 
Thus create a program that creates an array with shared pointers for shapes 
(The template array class and shape hierarchy was created in earlier exercises). 
Fill it with various shapes and print them. Check if the shapes are automatically deleted.
*/

#include <vector>
#include "boost/shared_ptr.hpp"
#include "circle.h"
#include "point.hpp"
#include "shape.hpp"
#include "array.hpp"
#include "array.cpp"
#include "line.h"

#include <iostream>
using namespace std;

int main() 
{
	
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;
	ShapeArray newArray(3);						//this creates a shape array of 3 shape pointers
	
	ShapePtr p1(new point(3.4, 2.5)); //make a shared pointer point
	ShapePtr l1(new line(point(3.2, 4.5), point(2.43, 32.3))); //make a shared pointer line
	ShapePtr c1(new circle(point(2.3, 3.2), 2.3)); //make a shared pointer circle
	//point and shape destructors are called after this because two points are created
	//for the line, and once copied, they are destroyed.

	//fill the shape pointer array
	newArray.setElement(0, p1);
	newArray.setElement(1, l1);
	newArray.setElement(2, c1);
	
	//print shapes
	cout << newArray[0] -> toString() << endl;
	cout << newArray[1] -> toString() << endl;
	cout << newArray[2] -> toString() << endl;

	//destructors are called
	return 0;
}




