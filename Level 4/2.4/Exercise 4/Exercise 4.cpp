/*
Normally, only member functions of a class can access the private members of that class. 
Global functions and other classes can’t access the private members of that class. 

You can make an exception to that rule by declaring certain functions or classes as friendS.
the << operator for sending the point or line to the std::ostream class had to be a 
global function and thus can’t access the private members. 

Move the << operator of Point and Line inside the class definition and declare it as friend. 

The function remains a global function but it can now access the data members directly without 
the need for calling the getters or ToString() function.

Normally, friends are to be avoided because THEY VIOLATE the data hiding principle. 
But in THE case of global operator functions, it makes sense because you 
want THE global operator functions to be member functionS.
*/

#include "point.hpp"
#include "line.h"
#include<iostream>
using namespace std;
int main() 
{
	point p1(2,3);
	point p2(8,9);
	line l1(p1, p2);
	cout << p1 << endl;
	cout << l1 << endl;
	return 0;
}