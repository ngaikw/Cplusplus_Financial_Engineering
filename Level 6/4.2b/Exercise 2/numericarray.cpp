#ifndef numericArray_CPP
#define numericArray_CPP

#include"differentSizeException.hpp"
#include"numericarray.hpp"
#include<cmath>
using namespace std;

template <class T> 
numericArray<T>::numericArray() : Array<T>()//default constructor
{  
}

template <class T> 
numericArray<T>::numericArray(int s) : Array<T>(s) 
{
}

template <class T>
numericArray<T>::numericArray(const numericArray<T>& nArray) : Array<T>(nArray) //copy constructor
{   
}

template <class T>    
numericArray<T>::~numericArray() //destructor
{
}

template <class T>    
numericArray<T>& numericArray<T>::operator = (const numericArray<T>& nArray) //assignment operator
{
	Array<T>::operator = (nArray); //call the base class assignment operator
    return *this;    
}

template <class T>
numericArray<T> numericArray<T>::operator * (const T& factor) const //* operator to scale elements by a factor of type T   
{
	numericArray<T> nA(size());								 //create new nArray object with same size as *this. (have to call size
															 //function because we cannot access private members of base class
    for (int i = 0; i < nA.size(); i++)
    {
		nA[i] = (*this)[i] * factor; //getElement(i) * factor;	same		 //load nArray object with scaled factor
		cout << "nA" << i << " " << nA[i] << endl;
	}
	
    return nA;
}

template <class T>
numericArray<T> numericArray<T>::operator + (const numericArray<T>& nA) 
{
	int iAsize = size();						    //store size in variable

	if (iAsize != nA.size())
	{
		throw differentSizeException();			   //throw an exception if the numeric arrays aren't the same size
	}


	numericArray<T> nA2(iAsize);				   //create a new nArray object

	for (int i = 0; i < size(); i++)
	{
		nA2[i] = (*this)[i] + nA[i];  //add elements of both arrays
	}


	return nA2;
    
}

template <class T>
T& numericArray<T>::dot(numericArray<T>& nA) //dot product function
{
	if (size() != nA.size())
	{
		throw differentSizeException();			   //throw an exception if the numeric arrays aren't the same size
	}

    T temp = 0;									   //create an object T to store the dot product

    for(int i = 0; i < size(); i++)
    {
		temp = (*this)[i] * nA[i];		   //multiply both indices
		temp += temp;							   //add to total
    }
	return temp;
}

#endif