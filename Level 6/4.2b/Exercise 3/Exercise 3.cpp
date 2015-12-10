#include "pointArray.cpp"
#include "point.hpp"
#include <iostream>
using namespace std;

int main()
{
	pointArray<point> p1(3);
	pointArray<point> p2(3);
	pointArray<point> bad(7);
	pointArray<point> newP(3);
	cout << "p1 size is " << p1.size() << endl;
	cout << "p2 size is " << p2.size() << endl;

	cout << "first point p1: " << p1[0] << endl;
	cout << "first point p2: " << p2[0] << endl;
	//change points:
	point a, b;
	a.X(4.2);
	a.Y(2.3);
	b.X(2.5);
	b.Y(5.6);
	p1.setElement(1, a);
	p2.setElement(2, b);
	cout << p1[1] << endl;
	cout << p2[2] << endl;
	try
	{
		cout << "length between two array points: " << p1.length(p2) << endl;
		cout << "this shouldn't print;" << p1.length(bad) << endl;				//should show error
	}
	catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	 p1 = p2;
	 cout << p1[2] << endl;

	 try
	 {
	 newP = p1 + p2;
	 cout << "p1" << p1[2] << endl;
	 cout << "p2" << p2[2] << endl;
	 cout << "newP" << newP[2] << endl;
	 newP = newP * 3.7;
	 cout << newP[2] << endl;
	 }
	 catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	 
	return 0;
}