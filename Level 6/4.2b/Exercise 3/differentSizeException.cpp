#include"differentSizeException.hpp"
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

differentSizeException::differentSizeException() : arrayException()
{
}

differentSizeException::~differentSizeException()
{
}

std::string differentSizeException::getMessage()
{
	return "The two arrays are of different size"; // getMessage function that overrides base class function
}
