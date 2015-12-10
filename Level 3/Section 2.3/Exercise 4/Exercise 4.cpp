

#include "point.hpp"
#include<iostream>
using namespace std;

int main()
{
	//part 1
	//In the test program create a const point and try to set the x-coordinate:
	const point cp(1.5, 3.9);
	//cp.X(0.3);
	//Compile the program. Did you get a compiler error? It should give a compiler error because you try to change a const object.
	//Yes, there is an error

	//part 2
	cout<<cp.X()<<endl;
	//this still gives an error. this is because the compiler doesn't know the function doesn't change anything.
	//so change getter functions as const functions
	//and change distance and tostring functions to const bc they don't change the point object as well.
	return 0;
}
