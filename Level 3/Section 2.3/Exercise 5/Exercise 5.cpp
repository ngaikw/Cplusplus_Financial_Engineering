/*
test program for line
*/
#include "line.h"
#include "point.hpp"
#include <iostream>
using namespace std;

int main() 
{
	point p1(3.4, 5.6);
	point p2(4.5, 6.7);
	line l(p1, p2);
	cout << l.toString() << endl;
	cout << l.length() << endl;
	return 0;
}