/*Make the setters and getters of the Point class inline functions. 
Use normal inline (outside the class declaration) for the getters and default inline 
(inside the class declaration) for the setters. 
Note that the implementation of the normal inline 
functions must be in the header file; else they will not be inlined.
*/
#include "point.hpp"
#include<iostream>
using namespace std;

int main()
{
	point p1; //create new point object
	cout << p1.X() << endl;
	cout << p1.Y() << endl;
	p1.X(2.3);
	p1.Y(3.4);
	cout << p1.X() << endl;
	cout << p1.Y() << endl;
	return 0;
}
