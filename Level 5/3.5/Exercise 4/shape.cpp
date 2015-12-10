#include"shape.hpp"
#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;

	Shape::Shape() : user_id(std::rand()) 			//default constructor
	{
		cout << "Shape constructor text" << endl;
	}

	Shape::Shape(const Shape& s) : user_id(s.user_id)	//copy constructor
	{	
	}

	Shape::~Shape()				    //destructor
	{	
		cout << "Shape destructor." << endl;
	}
	
	Shape& Shape::operator = (const Shape& s) //assignment operator
	{
		if (this == &s) return *this;
		user_id = s.user_id;
		return *this;

	}

	std::string Shape::toString() const //toString function returns id as string "ID:123"
	{	
		stringstream outString;
		outString << "ID: " << user_id;
		return outString.str();
	}

	int Shape::ID() const //ID function retrieves id of shpae	
	{
		return user_id;
	}