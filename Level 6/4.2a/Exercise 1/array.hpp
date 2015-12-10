/*
header file for array class
*/

#ifndef array_HPP
#define array_HPP

#include<iostream>
#include<string>


using namespace std;
template <class T> class Array
{
private:
	int a_size;
	T* m_data;
public:
	Array<T>(); //default constructor
	Array<T>(int s); //constructor with size argument
	Array<T>(const Array<T>& a);//copy constructor
	~Array<T>();//destructor

	Array<T>& operator = (const Array<T>& a); //assignment operator
	T& operator [] (int index); 
	const T& operator [] (int index) const;

	int size() const; //size operator that returns the size of the array
	void setElement(int place, T& replace); //function that sets an element. if index is out of bounds, ignore "set
	T& getElement(int place) const; //getElement returns element by reference. if index out of bounds return first element
};
#ifndef array_CPP 
#include"array.cpp"
#endif


#endif
