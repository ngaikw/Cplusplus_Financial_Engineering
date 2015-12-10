/*
Exercise 3
STL already contains many algorithms that work with containers. Use the count_if algorithm 
to count the number of elements smaller than a certain number. The count_if function accepts 
a functor. Thus pass it a global function that checks the double input is smaller than a certain value.

Replace the global checking function, by a function object. This is a class that overloads the round 
bracket operator that in this case has the same signature and functionality as the global function 
you created previously. Only in this case, the value to check for should not be a ‘literal’ value, but 
taken from a data member that was set in the constructor of the function object.

*/
#include <algorithm>
#include <numeric>
#include <list>
#include <functional>
#include "globalFunction.hpp"
#include <iostream>
#include <assert.h>
#include "lessThan.hpp"

using namespace std;
void main() 
{
	list<double> l;

	for (int s=0; s < 5; s++)
		l.push_back(s);
	int lessThanCount = count_if(l.begin(), l.end(), lessThan); //test the global function
	cout << "for global function : numbers less than 3 in l: " << lessThanCount << endl;

	//test for functor
	int lessThanCount2 = count_if(l.begin(), l.end(), less_x(3));
	cout << "for functor: numbers less than 3 in l: " << lessThanCount2 << endl;
	assert(lessThanCount == 3);
}