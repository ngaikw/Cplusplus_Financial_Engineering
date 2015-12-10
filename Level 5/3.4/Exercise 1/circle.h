/*
It has a center point and radius. Create the proper constructors, destructor, selector and modifier functions.
Also add functions for getting the diameter, area and circumference. Don’t forget a ToString() function.
*/
#ifndef circle_HPP
#define circle_HPP

#include "point.hpp"
#include <iostream>
#include <string>
using namespace std;
namespace Inna
{
	namespace CAD
	{
		class circle
		{
		private:
			point cent; //center as a point
			double rad; //radius as double
		public:
			circle();									//default constructor
			circle(const point& p, const double& r);	//constructor with center point and radius
			circle(const circle& c);					//copy constructor
			~circle();									//deconstructor
			point center() const;						//getter function for center
			double radius() const;						//getter function for radius
			void center(const point& p);				//setter function for center
			void radius(const double& r);				//setter function for radius
			double diameter() const;					//diameter
			double area() const;						//area
			double circum() const;						//circumferance
			std::string toString() const;				//string function to describe circle
			friend ostream& operator << (ostream& os, const circle& c); //global function for ostream
		};

		
	}
}
#endif