/*In the ToString() function of Pointand Line we also want to 
incorporate the ID from theShape base class.
• In the ToString() method of Point, call the ToString() method of the Shape base class: std::string s=Shape::ToString();
• Append the shape description string to the point description string before returning.
• Do this also for the ToString() function in the Line class (and Circle class).
• Test the application again. Is now the ID printed when printing a point or line? yes
*/

#include<iostream>
#include"shape.hpp"
#include"point.hpp"
#include"circle.h"
#include"line.h"

using namespace std;
using namespace Inna::CAD;

int main()
{
	point p(10, 20);
	Shape* sp; // Create pointer to a shape variable.
	sp = &p; // Point in a shape variable. 
	cout << sp -> toString() << endl;

	line l(point(1,2), point(3, 4)); // Create line.
	sp = &l; //now put line in shape variable
	cout << sp -> toString() << endl; 

	circle c; //create circle
	sp = &c; //now put circle in shape variable
	cout << sp -> toString() << endl;
	return 0;
}