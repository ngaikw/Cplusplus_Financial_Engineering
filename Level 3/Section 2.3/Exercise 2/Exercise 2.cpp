/*
Pass input point as “const reference” to make it impossible to change the input point from within the Distance() function
It should call the copy constructor fewer times than before. Also test if you can change the input point in the Distance() function.
This should result in a compiler error.

*/

#include "point.hpp"
#include<iostream>

int main() 
{
	double x, y, x2, y2;
	//ask user for x and y coordinates:
	cout << "Please enter 2 x coordinates" << endl;
	cin >> x >> x2;
	cout << "Please enter 2 y coordinates" << endl;
	cin >> y >> y2;
	point p1(x, y); //initialize pt1
	point p2(x2, y2); //initialize pt2
	p1.distance(p2);
	/*
	the constructor is called 0 times now.
	
	The code for trying to change the input values of the point passed to distance is in the "point.cpp" file
	*/
	return 0;
}
