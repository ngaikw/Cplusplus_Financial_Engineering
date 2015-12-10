#ifndef stackEmptyException_HPP
#define stackEmptyException_HPP
#include<stdlib.h>
#include"stackException.hpp"

class stackEmptyException : public stackException
{
public:
	stackEmptyException();					 //constructor	
	virtual ~stackEmptyException();			 //destructor

	std::string getMessage();				//declare abstract function for message
};

#endif