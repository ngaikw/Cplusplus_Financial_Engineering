#ifndef stackFullException_HPP
#define stackFullException_HPP
#include<stdlib.h>
#include"stackException.hpp"

class stackFullException : public stackException
{
public:
	stackFullException();					 //constructor	
	virtual ~stackFullException();			 //destructor

	std::string getMessage();				//declare abstract function for message
};

#endif