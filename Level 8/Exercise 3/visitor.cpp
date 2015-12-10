#include "visitor.hpp"

visitor::visitor() : m_dx(2.0), m_dy(2.0)
{
	cout << "visitor default constructor text" << endl;
}

visitor::visitor(double offX, double offY) : m_dx(offX), m_dy(offY)
{
	cout << "visitor constructor with arguments" << endl;
}

visitor::visitor(const visitor& v) : m_dx(v.m_dx), m_dy(v.m_dy)
{
	cout << "visitor copy constructor" << endl;
}

visitor::~visitor()
{
	cout << "visitor destructor" << endl;
}

void visitor::operator () (point& p) const
{
	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);
}

void visitor::operator () (line& l) const
{
	point startPNew(((l.start()).X() + m_dx), ((l.start()).Y() + m_dy));//make the scaled start point for line
	point endPNew(((l.end()).X() + m_dx), ((l.end()).Y() + m_dy)); //make the scaled end point
	l.start(startPNew); //set the new start point
	l.end(endPNew); //set the new end point
}

void visitor::operator () (circle& c) const
{
	point newCenter((c.center()).X() + m_dx, (c.center()).Y() + m_dy); //scale center
	c.center(newCenter); //set the new center point
}

