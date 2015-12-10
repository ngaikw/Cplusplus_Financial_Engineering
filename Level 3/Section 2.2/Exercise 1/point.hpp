/*header file for the Point class with private members for the x- and y-coordinates.

*/
#ifndef point_HPP
#define point_HPP

#include<iostream>
#include<string>
using namespace std;

class point
{
private:
	double xCoord; //x coordinate
	double yCoord; //y coordinate
public:
	point(); //default constructor
	point(const point& p); //copy constructor (2.3.1)
	point(double x, double y); //constructor that accepts x and y coordinates (2.3.1)
	~point();//destructor
	//old selectors
	double getX();//old
	double getY(); //old

	std::string toString() const;
	double distanceOrigin(); //for exercise 2.2.2
	double distance(const point& p); //for exercise 2.2.2, distance between 2 points, modified in exercise 2.3.2 to const referance
	double distance() const; //for exercise 2.3.3, renaming distanceorigin as distance
	
	//old modifiers
	void setX(double newx); //old
	void setY(double newy); //old

	//Exercise 2.3.3 renaming setter and getter functions  (now these are inline)
	double X() const; //new getter for x
	void X(double newx) {xCoord = newx;} //new setter for x
	double Y() const; //new getter for Y
	void Y(double newy) {yCoord = newy;} //new setter for Y

};

inline double point::X() const { return xCoord; }
inline double point::Y() const { return yCoord; }


#endif