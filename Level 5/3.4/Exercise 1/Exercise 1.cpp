#include"point.hpp"
#include "line.h"
#include<iostream>

using namespace std;
using namespace Inna::CAD;

int main() {
	line l;
	/*
	after changing point to colon syntax:
	number of constructor calls: 2
	destructor calls: 3
	assignment calls:0
	*/
	/*
	after changing constructor in line class
	number of constructor calls: 0
	destructor calls: 2
	assignment calls:0
	*/

	return 0;
}