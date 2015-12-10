/*
Exercise 3: Variant
a boost::variant stores one value that can be of one of the specified types. 
It is thus similar to a C union but it is type-safe.

Create a function to ask user what kind of shape to create. Then return the shape.

we can return the created shape as Shape* because all shapes have a common base 
class but that involves creating the shapes with new. Instead we can return the 
created shape a boost::variant which would also be needed if the shapes did not 
have a common base class.
create a typedef for a ShapeType variant that can contain a Point, Line or Circle. 
Next create a function that returns the variant. Within this function ask the user 
for the shape type to create. Then create the requested shape and assign it to the 
variant and return it.

Checking what kind a type is stored in the variant is cumbersome. Therefore the 
boost::variant supports visitors. A visitor is a class derived from boost::static_visitor<T> 
that has for each type that can be stored an operator () with the type as argument. 
The template argument is the return type of the operators ().
Now create a variant visitor that moves the shapes. The visitor is derived from 
boost::static_visitor<void> and must have members for the x- and y-offset that are set in the constructor. 
For each shape, create an operator () that changes the coordinates of the shape.

*/
#include <iostream>
#include <string>
using namespace std;

#include <boost/variant.hpp>
#include "point.hpp"
#include "shape.hpp"
#include "circle.h"
#include "line.h"
#include "visitor.hpp"

typedef boost::variant<point, line, circle> shapeVariant; //define typedef in global scope


shapeVariant input(){
	cout << "welcome" << endl;
	int n = 0;

	cout << "What type of shape? 0 for Point, 1 for line, 2 for circle" << endl;
	cin >> n;
	
	if (n == 0){ //get user input to make the point
		double x, y;
		cout <<"welcomepoint. enter x , then y coordinate " << endl;
		cin >> x >> y;
		return shapeVariant(point(x, y)); //return the point
	}
	else if (n == 1){ //get more user input to make the line
		double x1, y1, x2, y2;
		cout <<"welcome line. enter x and y coordinate of first point " << endl;
		cin >> x1 >> y1;
		cout << "now enter x and y coordinate of second point" << endl;
		cin >> x2 >> y2;
		return shapeVariant(line(point(x1,y1), point(x2,y2))); //return the line
	}
	else if (n == 2){ //more user inpur to make the circle
		double c1, c2, rad; 
		cout <<"welcome circle. enter x and y coordinate of center " << endl;
		cin >> c1 >> c2;
		cout << "enter the radius" <<endl;
		cin >> rad;
		return shapeVariant(circle(point(c1, c2), rad)); //return the circle
	}
}



int main() 
{
	shapeVariant ans = input();
	cout << ans << endl; //print out the input

	line l; //try to assign variant to line
	try 
	{
		l = boost::get<line>(ans);
		cout << l << endl;
	}
	catch (boost::bad_get& err) //if the variant didn't contain a line as the user inputed, there will be an error.
	{
		cout << "Error: " << err.what() << endl;
	}

	//now test visitor class
	double scaleX, scaleY;
	cout << "enter the x and y values you want to scale by: " << endl; //ask user for scale values
	cin >> scaleX >> scaleY;
	visitor v(scaleX, scaleY); //set scale coordinates

	boost::apply_visitor(v, ans); //move shape
	cout << "After scaling the point in this shape" << endl << ans << endl;
	return 0;
}
