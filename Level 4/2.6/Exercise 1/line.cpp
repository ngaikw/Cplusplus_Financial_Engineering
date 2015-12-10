#include "line.h"
#include <iostream>
#include <string>
#include <sstream>
namespace Inna
{
	namespace CAD
	{

		line::line() //constructor
		{
			point startPoint(0.0, 0.0);
			point endPoint(0.0, 0.0);
		}

		line::line(const point& p1, const point& p2) : startPoint(p1), endPoint(p2) //constructor w start and end point
		{
		}

		line::line(const line& l) //copy constructor
		{
			startPoint = l.startPoint;
			endPoint = l.endPoint;
		}

		line::~line() //destructor
		{
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
			return outString.str();
		}

		double line::length() const
		{
			double length;
			length = startPoint.distance(endPoint);
			return length;	
		}
	}
}