#include"stack.cpp"
#include"array.hpp"
#include"stackException.hpp"

#include<iostream>
using namespace std;

int main() 
{
	try
	{
	stack<double, 3> testStack;
	cout << "current index: " <<testStack.current() << endl;
	testStack.push(3.4); //push onto stack
	cout << "popped " << testStack.pop() << endl;
	cout << "this should be an error" << testStack.pop() << endl;
	}
	catch (stackException& sE)
	{
		cout << sE.getMessage() << endl;
	}
	catch(...)
	{		
		cout << "an unhandled exception has occured" << endl;
	}
	try
	{
		stack<double, 10> testStack;
		testStack.push(3.2);
		for (int i = 0; i < 12; i++)
			testStack.push(2.3); //fill up the array
	}
	catch(stackException& out)
	{
		cout << out.getMessage() << endl;
	}
	catch(...)
	{
		cout << "an unhandled exception has occured" << endl;
	}
	return 0;

}