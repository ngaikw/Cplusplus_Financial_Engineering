#ifndef pointArray_CPP
#define pointArray_CPP
#include <cmath>
#include "pointArray.hpp"
#include "arrayException.hpp"
#include "differentSizeException.hpp"

template <class point>
pointArray<point>::pointArray() : Array<point>()
{
}

template <class point>
pointArray<point>::pointArray(int s) : Array<point>(s)											
{
}

template <class point>
pointArray<point>::pointArray(const pointArray<point>& pArray) : Array<point>(pArray)						
{
}

template <class point>
pointArray<point>::~pointArray()
{
}

template <class point>
pointArray<point>& pointArray<point>::operator = (const pointArray<point>& pArray)
{
	Array<point>::operator = (pArray); //call base class assignment operator
	return *this;
}

template <class point>
pointArray<point> pointArray<point>::operator + (const pointArray<point>& pArray)
{
	if (size() != pArray.size())
		throw differentSizeException();
	
	pointArray<point> pArray2(size());

	for (int i = 0; i < size(); i++)
		pArray2[i] = (*this)[i] + pArray[i]; //add points,
	cout << pArray2[0] << endl;
	return pArray2;
}

template <class point>
pointArray<point> pointArray<point>::operator * (const double factor) const
{
	pointArray<point> pArray(size());					//create new array object
	for (int i = 0; i < size(); i++)						//call point operator *
		pArray[i] = (*this)[i] * factor;
	return pArray;
}

template <class point>
double pointArray<point>::length()
{
	double sum = 0;								
	for (int i = 1; i < size(); i++)
	{
		point before = (*this)[i-1];
		point current = (*this)[i];
		sum += before.distance(current);			//calculate distance between points
	}
	return sum;
}

#endif