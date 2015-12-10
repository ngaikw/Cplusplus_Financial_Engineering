/*
source file for array class
*/
#ifndef array_CPP
#define array_CPP
#include"arrayException.hpp"
#include"outOfBoundsException.hpp"
#include "array.hpp"

template <class T>
int Array<T>::default_m_data = 10;

template <class T>
Array<T>::Array() //default constructor 
{
	a_size = default_m_data;
	m_data = new T[a_size]; 
	cout << "array class default constructor" << endl;
}

template <class T>
Array<T>::Array(int s) //constructor with size argument
{
	a_size = s;
	m_data = new T[a_size];
	cout << "array class constructor with size arg" << endl;
}

template <class T>
Array<T>::Array(const Array<T>& a) //copy constructor
{
	a_size = a.a_size;
	m_data = new T[a_size];
	for (int i =0; i < a_size; i++)
	{
		m_data[i] = a.m_data[i];
	}
	cout << "array class copy constructor" << endl;
}

template <class T>
Array<T>::~Array()
{
	cout << "array class Destructor text" << endl;
	delete[] m_data;
}

template <class T>
void Array<T>::defaultSize(int size) 
{
	default_m_data = size;
}

template <class T>
int Array<T>::defaultSize() 
{
	return default_m_data;
}

template <class T>
Array<T>& Array<T>::operator = (const Array<T>& a) //assignment operator
{
	if (this != &a)
	{
		delete[] m_data; //delete old array
		a_size = a.a_size; //new size
		m_data = new T[a.a_size]; //make new array
		for (int i =0; i < a.a_size; i++)
		{
			m_data[i] = a.m_data[i]; //copy elements
		}
	}
	return *this;
}

template <class T>
T& Array<T>::operator [] (int index)
{
	if (index >= a_size || index < 0) //if the index is out of bounds,
	{
		throw outOfBoundsException(index); // error handler with outofboundsexception object
	}
	//else, return the point w specified index
	return m_data[index ];
}

template <class T>
const T& Array<T>::operator [] (int index) const
{
	if (index >= a_size || index < 0) //if the index is out of bounds,
	{
		throw outOfBoundsException(index); // error handler with outofboundsexception object
	}
	//else, return the point w specified index
	return m_data[index];
}

template <class T>
int Array<T>::aSize() const
{
	return a_size;
}

template <class T>
void Array<T>::setElement(int place, T& replace)
{
	if (place >= a_size || place < 0) //if the index is out of bounds,
	{
		//throw -1;
		throw outOfBoundsException(place); // error handler with outofboundsexception object
	}
	//else, replace specified index with specified replacement
	m_data[place] = replace; 
	return;
}

template <class T>
T& Array<T>::getElement(int place) const 
{
	if (place >= a_size || place < 0) //if the index is out of bounds,
	{
		//throw -1;
		throw outOfBoundsException(place); // error handler with outofboundsexception object
	}
	//else, return the specified index of the array
	return m_data[place ]; //assume the user starts the place number at 1
}
#endif