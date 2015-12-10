/*header file for the Point class with private members for the x- and y-coordinates.

*/
#ifndef point_HPP
#define point_HPP

#include"shape.hpp"
#include<iostream>
#include<string>
using namespace std;
namespace Inna
{
	namespace CAD
	{
		class point: public Shape
		{
		private:
			double xCoord; //x coordinate
			double yCoord; //y coordinate
		public:
			point(); //default constructor
			point(const point& p); //copy constructor (2.3.1)
			point(double x, double y); //constructor that accepts x and y coordinates (2.3.1)
			explicit point(double x); //constructor accepting one double, define as explicit
			virtual ~point();//destructor

			friend ostream& operator << (ostream& os, const point& p); 

			std::string toString() const;

			double distance(const point& p) const; //for exercise 2.2.2, distance between 2 points, modified in exercise 2.3.2 to const reference
			double distance() const; //for exercise 2.3.3, renaming distanceorigin as distance
	
			double X() const; //new getter for x
			void X(double newx) {xCoord = newx;} //new setter for x
			double Y() const; //new getter for Y
			void Y(double newy) {yCoord = newy;} //new setter for Y

			//member operator overloading
			point operator - () const;	//negate the coordinates
			point operator * (double factor) const; // Scale the coordinates.
			point operator + (const point& p) const; // Add coordinates.
			bool operator == (const point& p) const; // Equally compare operator.
			point& operator = (const point& source); // Assignment operator.
			point& operator *= (double factor); // Scale the coordinates & assign.
		};

		inline double point::X() const { return xCoord; }
		inline double point::Y() const { return yCoord; }
	}
}

#endif