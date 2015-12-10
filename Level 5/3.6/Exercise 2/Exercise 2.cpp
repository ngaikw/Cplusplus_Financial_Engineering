/*ArrayException base class and an OutOfBoundsExceptionderived class
• You can implement both exception classes in the header file for simplicity.
• Give the ArrayException an abstract GetMessage() function that returns a std::string.
• Give the OutOfBoundsException class a constructor with an int as argument 
that indicates the erroneous array index and store it in a data member.
• Override the GetMessage() function and let the implementation return a message 
string saying the given index is out of bounds.
• In the Array class, throw now a OutOfBoundsException object instead of an integer.
• Change the main program so that it catches the ArrayException base class and 
uses the GetMessage() function to display an error message.
*/
#include<iostream>

#include"array.hpp"
#include"shape.hpp"
#include"point.hpp"
#include"arrayException.hpp"
#include"outOfBoundsException.hpp"

using namespace std;
using namespace Inna::CAD;
using namespace Inna::Containers;

int main () 
{

	try
	{
		Array a; //create an array
		cout << a.getElement(13) << endl; //once in the try catch block, the error message appears.
	}
	catch(arrayException& out)
	{
		cout << "Index out of bounds!" << endl;
	}
	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}
	return 0;
}