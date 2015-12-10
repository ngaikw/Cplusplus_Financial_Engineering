#include"outOfBoundsException.hpp"
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

outOfBoundsException::outOfBoundsException()
{
}

outOfBoundsException::outOfBoundsException(int index)
{
	m_index = index;
}

outOfBoundsException::~outOfBoundsException()
{
}

std::string outOfBoundsException::getMessage()
{
	return "Index out of bounds"; // getMessage function
}
