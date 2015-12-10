/*
add a  << operator function.
has std::ostream o the left and point/line object on the right
create as a global function bc you can't add a member function to the std::ostream class
ostream& operator << (ostream& os, const Point& p); // Send to ostream.
Since it is a global function, you can’t access the private members of Point. 
To simplify things, you can use the ToString() method of Point to get the string to send to the os argument.
Also create a similar << operator for printing lines (and circles if you made a circle class). 
Adapt the test program to test the << operator for points and lines.
*/

#include "point.hpp"
#include "line.h"
#include "circle.h"
using namespace std;

int main() 
{
	point p1(3, 4);
	point p2(5, 6);
	line l1(p1, p2);
	double r = 3; // declare this for the radius of the circle
	circle c1(p1, r);
	cout << p1 << endl; //to test << operator for point class
	cout << l1 << endl; //test for line class
	cout << c1 << endl; //test for circle class

	return 0;
}
