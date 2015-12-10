#include "circle.h"
#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{
	point p1(2.0, 2.0);
	circle c(p1, 3.0);
	cout << c.toString() << endl;
	point p2(3.2, 4.89);
	c.center(p2);
	cout << c.toString() <<endl; //area and diameter shouldn't change
	c.radius(3.5);
	cout << c.toString() <<endl; //now area and diameter should change
	cout << c.radius() << endl; //getter function for radius 
	cout << c.center().toString() << endl; //getter function for center. call toString of point class 
	system("pause"); //add this because for some reason the command prompt closes even after using ctrl+ F5
	return 0;
}