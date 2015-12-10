/*
rename the DistanceOrigin() function to Distance().
rename the SetX() andGetX() functions to just X().The same is true for the setter and getter of the y-coordinate.
*/
#include "point.hpp"
#include<iostream>

int main() 
{
	double x, y;
	cout << "enter x coordinate" << endl;
	cin >> x;
	cout << "enter y coordinate" << endl;
	cin >> y;
	//make a point object
	point p1;
	//use new set function to set coordinates
	p1.X(x);
	p1.Y(y);
	//use new get function to print coordinates
	cout << "x coordinate of point is: " << p1.X() << endl;
	cout << "y coordinate of point is: " << p1.Y() << endl;
	//use new distanceOrigin function
	cout << "the distance between point and origin is: " << p1.distance() << endl;
	return 0;
}