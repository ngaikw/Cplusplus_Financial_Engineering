/*
Exercise 1: Templated Array Class
Tip: by placing the following code at the end of the array header file, but before the header file’s
#endif, the client can keep including the header file for template classes instead of the source file. 
Can you explain how this works?
This works because array.cpp is now included in the header file, and the client won't
have to add the .cpp file to their template classes.
#ifndef Array_cpp // Must be the same name as in source file #define
#include "Array.cpp"
#endif
*/

#include <iostream>		
#include <string>
using namespace std;	

#include"array.cpp"
#include"point.hpp" //to make an array of points


int main()
{
	int size = 3;
	Array<point> points(size);
	point p1(3,4);
	cout << points.size() << endl;
	points.setElement(1, p1);
	cout << points.getElement(1) << endl;
	Array<point> points_copy;
	cout << points_copy.size() << endl;
	points_copy = points;
	cout << points_copy.getElement(1) << endl;
	cout << points_copy.size() << endl;
	return 0;
}
