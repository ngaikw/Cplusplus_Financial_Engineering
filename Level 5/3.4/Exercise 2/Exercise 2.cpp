#include<iostream>
#include"shape.hpp"
#include"point.hpp"
#include"line.h"
#include"circle.h"
using namespace std;
using namespace Inna::CAD;

int main()
{
	Shape s; // Create shape.
	point p(10, 20); // Create point.
	line l(point(1,2), point(3, 4)); // Create line.
	cout<<s.toString()<<endl; // Print shape.
	cout<<p.toString()<<endl; // Print point.
	cout<<l.toString()<<endl; // Print line
	cout<<"Shape ID: "<<s.ID()<<endl; // ID of the shape.
	cout<<"Point ID: "<<p.ID()<<endl; // ID of the point. Does this work? yes
	cout<<"Line ID: "<<l.ID()<<endl; // ID of the line. Does this work? yes

	Shape* sp; // Create pointer to a shape variable.
	sp=&p; // Point in a shape variable. Possible? yes 
	cout<<sp->toString()<<endl; // What is printed? the ID of the point p is printed
	// Create and copy Point p to new point.
	point p2;
	p2=p;
	cout<<p2<<", "<<p2.ID()<<endl; // Is the ID copied if you do not call
	// the base class assignment in point? no
	return 0;
}