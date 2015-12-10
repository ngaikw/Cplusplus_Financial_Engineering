/*
source file for array class
*/
#include<iostream>
#include "array.hpp"
using namespace std;
namespace Inna
{
	namespace Containers
	{
		Array::Array() //default constructor allocates 10 elements
		{
			a_size = 10;
			m_data = new CAD::point[a_size]; //create the array of points on the heap
			cout << "default constructor" << endl;
		}

		Array::Array(int s) //constructor with size argument
		{
			a_size = s;
			m_data = new CAD::point[a_size];
			cout << "constructor with size arg" << endl;
		}

		Array::Array(const Array& a) //copy constructor
		{
			a_size = a.a_size;
			m_data = new CAD::point[a_size];
			for (int i =0; i < a_size; i++)
			{
				m_data[i] = a.m_data[i];
			}
			cout << "copy constructor" << endl;
		}

		Array::~Array()
		{
			cout << "Destructor text" << endl;
			delete[] m_data;
		}

		Array& Array::operator = (const Array& a) //assignment operator
		{
			if (this != &a)
			{
				delete[] m_data; //delete old array
				a_size = a.a_size; //new size
				m_data = new CAD::point[a.a_size]; //make new array
				for (int i =0; i < a.a_size; i++)
				{
					m_data[i] = a.m_data[i]; //copy elements
				}
			}
			return *this;
		}

		CAD::point& Array::operator [] (int index)
		{
			if (index > a_size) //if the index is out of bounds,
			{
				return m_data[0]; //return the first element
			}
			//else, return the point w specified index
			return m_data[index ];
		}

		const CAD::point& Array::operator [] (int index) const
		{
			if (index > a_size) //if the index is out of bounds,
			{
				return m_data[0]; //return the first element
			}
			//else, return the point w specified index
			return m_data[index ];
		}

		int Array::size() const
		{
			return a_size;
		}

		void Array::setElement(int place, CAD::point& replace)
		{
			if (place > a_size) //if the index is out of bounds,
			{
				return; //do nothing
			}
			//else, replace specified index with specified replacement
			m_data[place ] = replace; //assume the user starts the place number at 1
			return;
		}

		CAD::point& Array::getElement(int place) const 
		{
			if (place>a_size) //if the index is out of bounds,
			{
				return m_data[0]; //return the first element
			}
			//else, return the specified index of the array
			return m_data[place ]; //assume the user starts the place number at 1
		}
	}
}