/*
header file for array class
*/

#ifndef array_HPP
#define array_HPP

#include<iostream>
#include<string>
#include"point.hpp"
using namespace std;

class Array
{
private:
	int a_size;
	point* m_data;
public:
	Array(); //default constructor
	Array(int s); //constructor with size argument
	Array(const Array& a);//copy constructor
	~Array();//destructor

	Array& operator = (const Array& a); //assignment operator
	point& operator [] (int index); 
	const point& operator [] (int index) const;

	int size() const; //size operator that returns the size of the array
	void setElement(int place, point& replace); //function that sets an element. if index is out of bounds, ignore "set
	point& getElement(int place) const; //getElement returns element by reference. if index out of bounds return first element
	
};

#endif