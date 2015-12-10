#ifndef stackFullException_CPP
#define stackFullException_CPP
#include<stdlib.h>
#include"stackFullException.hpp"

stackFullException::stackFullException() : stackException()				//constructor	
{
}

stackFullException::~stackFullException()			 //destructor
{
}

std::string stackFullException::getMessage()				//declare abstract function for message
{
	return "Stack overflow";
}

#endif