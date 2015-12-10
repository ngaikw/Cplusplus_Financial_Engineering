/*
exercise 2: tuple
Boost tuples can be used to store different kinds of data as one entity.
It can be used if we need to combine data without the need to create a separate class.

Create a typedef for a Person tuple that contains a name, age and length.
Also create a function that prints the person tuple. 
Use the get<T>() member functions to retrieve the data. 

Create a few person tuple instances and print them.
Also increment the age of one of the persons. 
Note that to change a value of one of the tuple elements, 
you can also use the get<T>() function since it returns a reference to the value.
*/
#include <boost/tuple/tuple.hpp>	// Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples

#include <string>
#include <iostream>
using namespace std;

void printPerson(boost::tuple<string, int, double> person)
{
	cout << person.get<0>() << " is " << person.get<1>() << " years old. Height is: "
		<< person.get<2>() << " cm." << endl;
}

int main() 
{ 
	typedef boost::tuple<string, int, double> personTuple; //string=name, int=age, double = length 
	//create some people
	personTuple Brady("Brady", 23, 160);
	personTuple Grady("Grady", 24, 165);
	personTuple Shady("Shady", 10, 140);
	//print people
	printPerson(Brady);
	printPerson(Grady);
	printPerson(Shady);

	cout << "It was Shady's birthday! " << endl;
	
	Shady.get<1>() += 1; //add 1 to shady's age using get<T>() function

	printPerson(Shady);

	return 0;
}