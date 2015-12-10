#ifndef visitor_HPP
#define visitor_HPP

#include <iostream>
#include <string>
using namespace std;

#include <boost/variant.hpp>
#include "point.hpp"
#include "shape.hpp"
#include "circle.h"
#include "line.h"

class visitor: public boost::static_visitor<>
{
private:
	double m_dx;
	double m_dy;
public:
	visitor(); //default constructor
	visitor(double offX, double offY); //constructor with two arguments
	visitor(const visitor& v); //copy constructor
	~visitor(); //destructor

	void operator () (point& p) const;
	void operator () (line& l) const;
	void operator () (circle& c) const;

};
#endif