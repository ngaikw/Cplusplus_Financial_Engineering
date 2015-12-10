/* test program for the point class for exercise 2
	this tests the distance functions
*/
#include "point.hpp"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	double x, y, x2, y2;
	//ask user for x and y coordinates:
	cout << "Please enter 2 x coordinates" << endl;
	cin >> x >> x2;
	cout << "Please enter 2 y coordinates" << endl;
	cin >> y >> y2;
	//create a point object:
	point pt1;
	point pt2;
	//set coordinates:
	pt1.setX(x);
	pt1.setY(y);
	pt2.setX(x2);
	pt2.setY(y2);
	//print value returned from toString function:
	cout << "1st point: " << pt1.toString() << endl;
	cout << "2nd point: " << pt2.toString() << endl;
	//distance between point 1 and the origin
	cout << "The distance between the first point and origin is " << pt1.distanceOrigin() <<endl;
	cout << "The distance between the two points is " << pt1.distance(pt2) << endl;
	/*cout << "The x coordinate is: " << pt1.getX() << endl;
	cout << "The y coordinate is: " << pt1.getY() << endl;*/

	return 0;
}