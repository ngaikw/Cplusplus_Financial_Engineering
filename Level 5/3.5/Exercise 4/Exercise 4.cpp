/*
Create the Draw() function in the Shape base class and override it in the derived classes
Simulate drawing by just printing some text.
Try to create an instance of the Shape class. Is this possible?
no. instances of a class are not possible after is an ABC. 
but we can declare pointers to an ABC.
*/

#include<iostream>
#include"shape.hpp"
#include"point.hpp"
#include"circle.h"
#include"line.h"


using namespace std;
using namespace Inna::CAD;

int main()
{
	Shape* shapes[4];
	shapes[0] = new line;
	shapes[1] = new point;
	shapes[2] = new line(point(1.0, 2.5), point(3.4, 5.2));
	shapes[3] = new circle;
	for (int i=0; i < 4; i++) shapes[i]->Draw();
	for (int i=0; i < 4; i++) delete shapes[i];
	return 0;
}