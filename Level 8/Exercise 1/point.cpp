/*source file that implements the point class
--member functions placed in source file
date: 3.14.15
*/

#include"point.hpp"
#include<iostream>
#include<sstream>
#include<string>
#include<cmath>

using namespace std;

point::point(): xCoord(0.0), yCoord(0.0), Shape() //default constructor
{
	cout << "point class default constructor" << endl;
}


point::point(const point& p) : xCoord(p.xCoord), yCoord(p.yCoord), Shape(p) /*give copy constructor of base class argument of the derived
																			class copy constructor. If the copy constructor from the derived
																			class isn't specified as the constructor that needs to be called,
																			the default constructor will be called and base part won't be copied*/
																				    
{
	cout << "point class copy constructor text" << endl; //add text to copy constructor
}

point::~point() //destructor
{
	cout << "point class destructor" << endl;
}

point::point(double x, double y) : xCoord(x), yCoord(y) 
{
}

point::point(double x): xCoord(x), yCoord(x) 
{
}

ostream& operator << (ostream& os, const point& p)
{
	os << "Point("<<p.xCoord<<", "<<p.yCoord<<")";//p.toString();
	return os;
}

std::string point::toString() const
{
	stringstream outString; //create a stringstream variable
	std::string s = Shape::toString(); //call toString of Shape function
	outString << "Point(" << xCoord << ", " << yCoord << ") " << s; //this puts what we want to print into the outString stream				
	return outString.str(); //retrieve string from string buffer and return it
}

double point::distance(const point& p) const//this uses another point to find the distance betwen this new point and current point
{
	double xNew, yNew, dist2;
	xNew = p.xCoord; //get x coordinate of new p object
	yNew = p.yCoord; //get y coordinate of new p object
	dist2 = sqrt(pow((xNew - xCoord), 2.0) + pow((yNew - yCoord), 2.0)); //distance formula
	return dist2;
}

double point::distance() const //this is the new distanceOrigin() function, exercise 2.3.3
{
	double dist;
	dist = sqrt(xCoord * xCoord + yCoord * yCoord); //distance formula
	return dist;
}

//member operator overloading

point point::operator - () const	//negate the coordinates
{
	return point( -xCoord, -yCoord);
}
point point::operator * (double factor) const // Scale the coordinates.
{
	return point( factor * xCoord, factor * yCoord);
}
point point::operator + (const point& p) const // Add coordinates.
{ //add x and y coordinates separately
	return point( p.xCoord + xCoord, p.yCoord + yCoord);
}
bool point::operator == (const point& p) const // Equally compare operator.
{ //the two points are equal if the x coordinates and y coordinates are equal
	return (p.xCoord == xCoord && p.yCoord == yCoord); 

}	
point& point::operator = (const point& source) // Assignment operator.
{
	if (this == &source) //exit if same object
		return *this;
			
	Shape::operator = (source); //call the base class assignment operator

	xCoord = source.xCoord;
	yCoord = source.yCoord;
			
	cout << "assignment operator text" << endl;
	return *this;
}	
point& point::operator *= (double factor) // Scale the coordinates & assign.
{
	return (*this) * factor;
}

void point::Draw() 
{
	cout << "Point drawing" << endl;
}
