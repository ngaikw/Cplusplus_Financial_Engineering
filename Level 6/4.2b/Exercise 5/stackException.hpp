#ifndef stackException_HPP
#define stackException_HPP
#include<stdlib.h>
#include<string>

class stackException
{
public:
	stackException();					 //constructor	
	virtual ~stackException();			 //destructor

	virtual std::string getMessage() = 0; //declare abstract function for message
};

#endif