/*
base class Shape header file
*/
#ifndef shape_HPP
#define shape_HPP

#include<stdlib.h>
#include<iostream>
#include<sstream>
#include<string>

class Shape
{
private:
	int user_id;
public:
	Shape();				//default constructor
	Shape(const Shape& s);	//copy constructor
	virtual ~Shape();				//destructor
	Shape& operator = (const Shape& s); //assignment operator
	virtual std::string toString() const; //toString function returns id as string"ID:123"
	int ID() const;//ID function retrieves id of shape
	virtual void Draw() = 0 const; // virtual member function for draw. in header set to 0,
							 // no corresponding code in source file
};
#endif