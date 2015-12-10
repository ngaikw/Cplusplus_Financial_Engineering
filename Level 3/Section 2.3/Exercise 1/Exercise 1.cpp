/*
1. In the Point class constructor and destructor, add some code that displays some text. 
In the main program, make sure you use the Distance() function to calculate the distance 
between two points. Run the program and count how many times the constructor and destructor are called. 
Are they the same?

Constructor is called: 2 times
Destructor is called: 3 times
they are not called the same number of times.

2.Now add a copy constructor to the Point class that also displays some text. Also add a constructor that 
accepts x- and y-coordinates so you can create a point with the right values without using the set functions. 
Use this constructor to create the point from the user input.
Run the program again and count the number of times the constructors and destructor are called. 
Is the copy constructor called and is the number of constructor calls now the same as the number of destructor calls?



if we are initializing two points:
copy constructor is called once,
constructor calls: 0
destructor calls: 3

*/
#include "point.hpp"
#include<iostream>
#include<string>

using namespace std;
int main()
{
	double x, y, x2, y2;
	//ask user for x and y coordinates:
	cout << "Please enter 2 x coordinates" << endl;
	cin >> x >> x2;
	cout << "Please enter 2 y coordinates" << endl;
	cin >> y >> y2;
	////FOR PART 1 OF THE EXERCISE:
	////create 2 point objects:
	//point pt1; //constructor called because default object is created
	//point pt2; //constructor called because default object is created
	////set coordinates:
	//pt1.setX(x);
	//pt1.setY(y);
	//pt2.setX(x2);
	//pt2.setY(y2);

	//pt1.distance(pt2); 

	//FOR PART 2 OF THE EXERCISE:
	point part2point(x, y);
	point part2point2(x2, y2);
	part2point.distance(part2point2); //copy constructor called
	//because object is passed by value to the distance function

	return 0;
}
