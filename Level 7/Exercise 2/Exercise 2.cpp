/*
Exercise 2:
Using iterators you can iterate a STL container without knowing which 
container it is. In this exercise you create a function that calculates 
the sum of a container with doubles.
• Create a template function called Sum() that accepts the template argument
T as input and returns a double. The template argument will be a container.
• In the implementation get an iterator (T::const_iterator) for the end. 
Then create a loop that iterates the container T and adds all values. Finally return the sum.
• In the main program, call the Sum() function for the different 
container from the previous exercise.

The Sum() function created calculates the sum of the complete container. Also create a Sum() 
function that calculates the sum between two iterators. The function then uses the 
template argument for the iterator type and accepts two iterators, the start and end iterator.
*/
#include<list>
#include<vector>
#include<map>
#include<iterator>
#include<string>
#include <iostream>
using namespace std;

template <class T>
double sum(const T &input) //sum function for vector and list
{
	double sum = 0;
	T::const_iterator i;
	for (i = input.begin(); i != input.end(); ++i)
	{
		sum += (*i);
	}

	return sum;
}

template <class T, class T2>
double sum(const std::map<T, T2> &input) //sum function for map
{
	double sum = 0;
	std::map<T, T2>::const_iterator k;
	for (k = input.begin(); k != input.end(); ++k)
	{
		sum = sum + (k->second); // ->second gives you access to the value, -> first gives you access to the key.
	}

	return sum;
}

template <class T>
double sum(const T &i1, const T &i2) //sum function between two iterators for vector and list
{
	double sum = 0;
	T iter;
	for (iter = i1; iter != i2; ++iter)
	{
		sum += (*iter);
	}

	return sum;
}

//why does the following not work? I thought we couldn't pass iterators as arguments into the function?
//when i tried to pass iterators as function for the sum function for lists and vectors, it didn't work.
//i also saw as per this thread:
//double sum(const std::map<string, double> &i1, const std::map<string, double> &i2) //sum function between two iterators for map
//{
//	double sum = 0;
//	std::map<string, double> iter;
//	for (iter = i1; iter != i2; ++iter)
//	{
//		sum += (iter -> second);
//	}
//
//	return sum;
//}

double sum(const std::map<string, double>::const_iterator &i1, const std::map<string, double>::const_iterator &i2) //sum function between two iterators for map
{
	double sum = 0;
	std::map<string, double>::const_iterator iter;
	for (iter = i1; iter != i2; ++iter)
	{
		sum += (iter -> second);
	}

	return sum;
}

void main()
{
	std::list<double> l(5);
	for (int j = 0; j < 5; j++)
		l.push_back(j);
	cout << "sum of list: " << sum(l) << endl;
	list<double>::const_iterator startIter = l.begin();
	list<double>::const_iterator endIter = l.end();
	cout << "sum of list" << sum(startIter, endIter) << endl;

	std::vector<double> v(3,200);
	vector<double>::const_iterator startIter2 = v.begin();
	vector<double>::const_iterator endIter2 = v.end();
	cout << "sum of vector: " << sum(v) << endl;
	cout << "sum of vector: " << sum(startIter2, endIter2) << endl;

	std::map<string, double> m;
	m["aa"] = 2.3;
	m["snba"] = 2.5;
	std::map<string, double>::const_iterator startIter3 = m.begin();
	std::map<string, double>::const_iterator endIter3 = m.end();
	cout << "sum of map: " << sum(startIter3, endIter3) << endl;
	cout << "sum of map: " << sum(m) << endl;
}
