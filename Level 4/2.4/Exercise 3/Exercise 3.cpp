/*
exercise 3: constructors as conversion operator
added constructor that accepts 1 double as argument to point class

*/
#include"point.hpp"
#include<iostream>

using namespace std;

int main()
{

	point p(1.0, 1.0);
	/*
	if (p==1.0) cout<<"Equal!"<<endl;
	else cout<<"Not equal"<<endl;
	*/
	/*
	the code above does compile 
	the new constructor with the single double argument
	is used to convert (p==1.0) into a point object.
	BUT
	once we define the constructor as explicit, we have to 
	explicitly use the constructor as conversion operator and only
	the code below compiles.
	*/

	if (p==(point)1.0) cout<<"Equal!"<<endl;

	return 0;
}