#ifndef pointArray_HPP
#define pointArray_HPP

#include "array.hpp"
#include "point.hpp"


template <class point>
class pointArray:public Array<point>
{
	//inherits data members from array.cpp
public:
	pointArray<point>();												//default constructor
	pointArray<point>(int s);											//constructor with size argument
	pointArray<point>(const pointArray<point>& pArray);						//copy constructor
	
	virtual ~pointArray<point>();										//destructor
	pointArray<point>& operator = (const pointArray<point>& pArray);//assignment operator
	pointArray<point> operator + (const pointArray<point>& pArray); //plus operator
	pointArray<point> operator * (const double factor) const;				//multiplication operator
	double length();								//length function 


};

#endif