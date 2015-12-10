/*
Exercise 1
One of the features of STL are the containers. In this exercise you 
will practice with the different STL containers. In the main program:
• Create a list of doubles and add some data. Use the front() and back()
functions to access the first and last element.
• Create a vector of doubles and add some data. Then use the index operator
to access some elements. Also make the vector grow.
• Create a map that maps strings to doubles. Fill the map and access elements
using the square bracket operator.
*/


#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

void main() {
	cout << "part 1: " << endl;
	std::list<double> l(6); //create a list of doubles
	for (int i = 0; i < 6; i++) {
		l.push_back(i); //add data
		cout << l.back() << endl;
	}
	cout << "front object should be 0: " << l.front() << endl;
	cout << "last object should be 5: " << l.back() << endl;
	l.push_back(4);
	cout << "last object changed: " << l.back() << endl;

	cout << "part 2: " << endl;
	std::vector<double> v; //create a vector, don't specify size
	for (int i = 0; i < 5; i++) {
		v.push_back(i); //add data, this makes the vector grow in size
		cout << i << endl;
		cout << v[i] << endl;
	}
	cout << "2nd element should be 1: " << v[1] << endl;

	cout << "part 3: " << endl;
	std::map<string, double> myMap;
	myMap["i"] = 2.3;
	myMap["like"] = 2.4;
	myMap["sushi"] = 2.5;
	cout << "size: " << myMap.size() << endl;
	cout << "sushi: " << myMap["sushi"] << endl;


}