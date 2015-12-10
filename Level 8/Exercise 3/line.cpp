#include "line.h"
#include <iostream>
#include <string>
#include <sstream>

	line::line() : startPoint(0.0, 0.0), endPoint(0.0, 0.0), Shape() //constructor
	{
	}

	line::line(const point& p1, const point& p2) : startPoint(p1), endPoint(p2) //constructor w start and end point
	{
	}

	line::line(const line& l) : startPoint(l.startPoint), endPoint(l.endPoint), Shape(l) //copy constructor
	{
	}

	line::~line() //destructor
	{
		cout << "Line destructor." << endl;
	}

	ostream& operator << (ostream& os, const line& h)
	{
		os << "startPoint of line is: " << h.startPoint << ". endPoint of line is: " << h.endPoint;
		return os;
	}

	//getter functions:
	point line::start() const
	{
		return startPoint;
	}

	point line::end() const
	{
		return endPoint;
	}
	//setter functions:
	void line::start(const point& p)
	{
		startPoint = p;
	}

	void line::end(const point& p)
	{
		endPoint = p;
	}

	std::string line::toString() const //call on toString for each start and end point to print these points
	{
		stringstream outString; //create stringstream variable
		outString << "startPoint of line is: " << startPoint.toString() << ". endPoint of line is: " <<endPoint.toString();
		std::string s = Shape::toString(); //call toString of Shape function
		return outString.str();
	}

	double line::length() const
	{
		double length;
		length = startPoint.distance(endPoint);
		return length;	
	}

	void line::Draw() 
	{
		cout << "Line drawing" << endl;
	}
