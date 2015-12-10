#ifndef numericArray_HPP
#define numericArray_HPP

#include"array.hpp"

template <class T> 
class numericArray:public Array<T>
{
//inherits data members from array.cpp

public:
    numericArray<T>();								 //default constructor
	numericArray<T>(int s);							 //constructor with size argument
    numericArray<T>(const numericArray<T>& nArray); //copy constructor
    
    virtual ~numericArray<T>(); //destructor

    numericArray<T>& operator = (const numericArray<T>& nArray); //assignment operator

    numericArray<T> operator * (const T& factor) const; //* operator to scale elements by a factor    

    numericArray<T> operator + (const numericArray<T>& nA); //+ operator to add numeric arrays

    T& dot(numericArray<T>& nA); //dot product function
}; 
#endif