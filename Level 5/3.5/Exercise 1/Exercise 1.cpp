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
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. 
	cout << sp -> toString() << endl; //this prints out the point toString

	line l(point(1,2), point(3, 4)); // Create line.
	sp = &l; //now put line in shape variable
	cout << sp -> toString() << endl; //this prints out the line toString

	return 0;
}