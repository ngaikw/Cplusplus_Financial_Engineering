/*
test file to test namespaces
*/

#include "point.hpp"
#include "circle.h"
#include "array.hpp"
#include "line.h"
#include <iostream>

using namespace std;
using namespace Inna::CAD;
using namespace Inna::Containers;

int main()
{
	//part 2 full namespace for point class
	Inna::CAD::point p1(3,4);
	Inna::CAD::point p2(5,6);
	cout << p1 << endl;


	//part 3 declaration for using single class
	line l(p1,p2);
	cout << l << endl;
	
	//part 4 declaration for complete namespace (containers)
	Inna::Containers::Array a;
	cout << a[3] << endl;

	//part 5 create shorter alias for Inna::CAD namespace
	namespace C = Inna::CAD;
	C::circle circ;
	cout << circ << endl;
	return 0;
}