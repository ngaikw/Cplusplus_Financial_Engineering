#ifndef stackEmptyException_CPP
#define stackEmptyException_CPP
#include<stdlib.h>
#include"stackEmptyException.hpp"

stackEmptyException::stackEmptyException() : stackException()				//constructor	
{
}

stackEmptyException::~stackEmptyException()			 //destructor
{
}

std::string stackEmptyException::getMessage()				//declare abstract function for message
{
	return "Stack underflow";
}

#endif