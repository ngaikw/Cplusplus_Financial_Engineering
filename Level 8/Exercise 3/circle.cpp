#define _USE_MATH_DEFINES
#include "circle.h"
#include "point.hpp"
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

circle::circle() : cent(0.0, 0.0), rad(1.0), Shape() //default constructor
{
}

circle::circle(const point& p, const double& r) : cent(p), rad(r) 
{
}

circle::circle(const circle& c) : cent(c.cent), rad(c.rad), Shape(c) //copy constructor
{
}

circle::~circle() //destructor
{
}

point circle::center() const
{
	return cent;
}

double circle::radius() const
{
	return rad;
}

void circle::center(const point& p)
{
	cent = p; //reset center
}

void circle::radius(const double& r)
{
	rad = r;
}

double circle::diameter() const
{
	return (rad * 2.0);
}

double circle::area() const
{
	return (M_PI * rad * rad);
}

double circle::circum() const
{
	return (M_PI * rad * 2.0);
}

std::string circle::toString() const
{
	stringstream outString;
	std::string s = Shape::toString(); //call toString of Shape function
	outString << "The center of this circle is: (" << cent.X() 
		<< ", " << cent.Y() << "), radius is: " << rad <<". area is: "
		<< area() << "." << endl << "circumference is: " << circum() << " " << s;
	return outString.str();
}

ostream& operator << (ostream& os, const circle& c)
{
	os << "The center of this circle is: (" << c.cent.X() 
		<< ", " << c.cent.Y() << "), radius is: " << c.rad <<". area is: "
		<< c.area() << "." << endl << "circumference is: " << c.circum();
	return os;
}

void circle::Draw() 
{
	cout << "Circle drawing" << endl;
}
