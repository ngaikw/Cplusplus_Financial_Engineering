#include"stack.cpp"
#include"array.hpp"
#include"point.hpp"
#include<iostream>
using namespace std;

int main()
{
	stack<double> testStack;
	try
	{
	cout << "current index: " <<testStack.current() << endl;
	testStack.push(3.4); //push onto stack
	cout << "popped " << testStack.pop() << endl;
	cout << "this should be an error" << testStack.pop() << endl;
	}
	catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	cout << "current index " << testStack.current() << endl;
	try
	{
		testStack.push(3.2);
		for (int i = 0; i < 12; i++)
			testStack.push(2.3); //fill up the array
	}
	catch(arrayException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	cout << "current: " << testStack.current() << endl;
	return 0;
}
