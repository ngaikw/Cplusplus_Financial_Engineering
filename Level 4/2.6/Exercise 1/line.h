/*header file for the line class
line class has a start and end point. has 2 point objects as data members
-use const arguments, const functions, and pass objects by reference where applicable.
-use const function for member functions which don't change the point object
*/
#ifndef line_HPP
#define line_HPP

#include "point.hpp"
#include <iostream>
#include <string>

using namespace std;
namespace Inna
{
	namespace CAD
	{
		class line
		{
		private:
			point startPoint;
			point endPoint;
		public:
			line();											//default constructor
			line(const point& p1, const point& p2);			//constructor with start and end point
			line(const line& l);							//copy constructor
			~line();										//destructor
	
			friend ostream& operator << (ostream& os, const line& h); //friend function for << operator
	
			point start() const;							//getter function for start point, set as constant function because it doesn't modify the line
			point end() const;								//getter function for end point 
			void start(const point& p);						//setter function for start point. takes a const because the point shouldn't be modified
			void end(const point& p);						//setter function for end point. 
			std::string toString() const;					//tostring function to return description of the line
			double length() const;   						//length function that returns length of the line. you can use distance function from point object.
		};
	}
}

#endif