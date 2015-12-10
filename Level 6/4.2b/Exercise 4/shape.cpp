#include"shape.hpp"
#include<iostream>
#include<sstream>
#include<string>
#include<stdlib.h>
using namespace std;

	Shape::Shape() : user_id(std::rand()) 			//default constructor
	{
		cout << "Shape class constructor text" << endl;
	}

	Shape::Shape(const Shape& s) : user_id(s.user_id)	//copy constructor
	{	
		cout << "shape class copy constructor" << endl;
	}

	Shape::~Shape()				    //destructor
	{	
		cout << "Shape class destructor." << endl;
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

	void Shape::Print() const
	{
		cout << toString() << endl; //print out string returned in toString function
	}