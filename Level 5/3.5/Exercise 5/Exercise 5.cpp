/*
create a Print() function that is printing the shape information to the cout object. 
ThePrint() function can use the ToString() to obtain the string to print.
• Add a Print() function to the Shape class.
• In this function, call the ToString() function and send the result to the cout object.
• In the test program, create a point and line object and call the Print() function. 
Does it print the right information even when point and line do not have the Print() function?
yes! cool!
*/
#include<iostream>
#include<sstream>
#include"shape.hpp"
#include"point.hpp"
#include"line.h"


using namespace std;
using namespace Inna::CAD;

int main()
{
	point p(10, 20); // Create point.
	line l(point(1,2), point(3, 4)); // Create line.

	p.Print(); //print point
	l.Print(); //print line
	return 0;
}