/*
If not done already, print some text in the destructors of the Shape, 
Point and Line classes. 
Will the proper destructors (including the destructor of the Shape base class) 
be called? In this case, the derived class destructor will only be called 
when the destructor is declared virtual in the base class. Do this 
in the Shape class and run the code again. Are the proper destructors called now?

Answer: If the base class destructor is not declared virtual,only the base class destructor
will be called. Thus, the proper destructors are called once we set the base class destructor
as virtual.
*/
#include<iostream>
#include"shape.hpp"
#include"point.hpp"
#include"line.h"


using namespace std;
using namespace Inna::CAD;

int main() 
{
	Shape* shapes[3];
	shapes[0]=new Shape;
	shapes[1]=new point;
	shapes[2]=new line;
	for (int i=0; i!=3; i++) delete shapes[i];

	return 0;
}