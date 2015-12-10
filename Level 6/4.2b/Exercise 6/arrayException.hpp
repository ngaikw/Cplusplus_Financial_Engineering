#ifndef arrayException_HPP
#define arrayException_HPP

#include<stdlib.h>
#include<string>
using namespace std;

class arrayException
{
public:
	arrayException();					   //default constructor
	virtual ~arrayException();			   //destructor
	virtual std::string getMessage() = 0;  //abstract function 
};

#endif



