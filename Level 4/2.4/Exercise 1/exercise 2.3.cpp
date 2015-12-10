/* use this program to test the operators */
#include"point.hpp"
#include<iostream>

using namespace std;

int main() 
{
	//declare two points
	point p1(3, 4);
	point p2(5, 6);

	point p3 = -p1; //test negation operator

	point p4 = p1 * 5; //test scaling operator

	point p5 = p1 + p2; //add coordinates

	cout << p3.toString() << endl;
	cout << p4.toString() << endl;
	cout << p5.toString() << endl;
	if (p1 == p2) cout << "True" << endl;
	else cout << "False" << endl; //this should return false
	
	//now set p2 equal to p1
	p2 = p1;
	if (p1 == p2) cout << "True" <<endl;
	else cout << "False" << endl; //now this should return true

	//now set p2 to 2 times p1
	p2 *= 2;
	cout << p2.toString() << endl;


	return 0;
}