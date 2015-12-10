#ifndef outOfBoundsException_HPP
#define outOfBoundsException_HPP

#include"arrayException.hpp"
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

class outOfBoundsException: public arrayException
{
private:
	int m_index;
public:
	outOfBoundsException(); //default constructor
	outOfBoundsException(int index); //constructor taking int as argument
	virtual ~outOfBoundsException(); //destructor

	std::string getMessage(); //getMessage function
};

#endif