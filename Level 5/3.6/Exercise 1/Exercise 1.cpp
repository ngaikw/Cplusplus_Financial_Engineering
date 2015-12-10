/*
Bounds Checking Array
Change the Array class to throw exceptions:
• In the GetElement(), SetElement() and index operator throw -1 if the index was too small or too big.
• In the main program, create an Array object and access an element that does not exist.
Run the program. What happens?
DEBUG ERROR! 
• The exception must be caught, so place the code inside a try ... catch block that catches an int.
• In the catch handler, print an error message.
*/

#include"array.hpp"
#include"shape.hpp"
#include"point.hpp"

using namespace std;
using namespace Inna::CAD;
using namespace Inna::Containers;

int main() 
{
	try
	{
		Array a; //create an array
		cout << a.getElement(13) << endl; //once in the try catch block, the error message appears.
	}
	catch(int err)
	{
		if (err == -1) cout << "Index out of bounds!" << endl;
	}
	catch(...)
	{
		cout << "An unhandled exception has occured" << endl;
	}
	return 0;
}