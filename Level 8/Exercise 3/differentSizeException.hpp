#ifndef differentSizeException_HPP
#define differentSizeException_HPP

#include"arrayException.hpp"
class differentSizeException: public arrayException
{

public:
	differentSizeException(); //default constructor
	virtual ~differentSizeException(); //destructor

	std::string getMessage(); //getMessage function
};

#endif