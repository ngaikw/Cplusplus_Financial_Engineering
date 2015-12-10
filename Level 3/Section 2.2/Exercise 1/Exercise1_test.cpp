/* test program for the point class
*/
#include "point.hpp"
#include<iostream>
#include<string>

using namespace std;

int main()
{
	double x, y;
	//ask user for x and y coordinates:
	cout << "Please enter an x coordinate" << endl;
	cin >> x;
	cout << "Please enter a y coordinate" << endl;
	cin >> y;
	//create a point object:
	point pt1;
	//set coordinates:
	pt1.setX(x);
	pt1.setY(y);
	//print value returned from toString function:
	cout << pt1.toString() <<endl;
	cout << "The x coordinate is: " << pt1.getX() << endl;
	cout << "The y coordinate is: " << pt1.getY() << endl;

	return 0;
}