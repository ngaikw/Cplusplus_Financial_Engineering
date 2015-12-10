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

point::point()
{
	xCoord = 0.0;
	yCoord = 0.0;
	cout << "Welcome to the program." << endl;//add some text to the constructor, exercise 2.3.1
}
point::~point()
{
	cout << "Bye." << endl; //2.3.1 add text to deconstructor
}
point::point(const point& p) //copy constructor 
{
	xCoord = p.xCoord;
	yCoord = p.yCoord;
	cout << "copy constructor text" << endl; //add text to copy constructor
}

point::point(double x, double y) : xCoord(x), yCoord(y) //initialize using colon syntax
{
}

double point::getX() //get the x value
{
	return xCoord;
}

double point::getY() //get the y value
{
	return yCoord;
}

std::string point::toString() const
{
	stringstream outString; //create a stringstream variable
	outString<< "Point("<<xCoord<<", "<<yCoord<<")"; //this puts what we want to print into the outString stream
	return outString.str(); //retrieve string from string buffer and return it
}

double point::distanceOrigin() //calculates the distance between origin and current point
{
	double dist;
	dist = sqrt(xCoord * xCoord + yCoord * yCoord); //distance formula
	return dist;
}

double point::distance(const point& p) //this uses another point to find the distance betwen this new point and current point
{
	double xNew, yNew, dist2;
	xNew = p.xCoord; //get x coordinate of new p object
	yNew = p.yCoord; //get y coordinate of new p object
	//exercise 2.3.2 to change the input point p , results in error "...conversion loses qualifiers"
	/*xNew = p.setX(3.2); 
	yNew = p.setY(3.6); */
	
	dist2 = sqrt(pow((xNew - xCoord), 2.0) + pow((yNew - yCoord), 2.0)); //distance formula
	return dist2;
}

double point::distance() const //this is the new distanceOrigin() function, exercise 2.3.3
{
	double dist;
	dist = sqrt(xCoord * xCoord + yCoord * yCoord); //distance formula
	return dist;
}

void point::setX(double newX) //set a new xCoord value
{
	xCoord = newX;
}

void point::setY(double newY) //set a new yCoord value
{
	yCoord = newY;
}

