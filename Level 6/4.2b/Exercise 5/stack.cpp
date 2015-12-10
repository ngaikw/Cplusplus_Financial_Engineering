#ifndef stack_CPP
#define stack_CPP

#include "stack.hpp"
#include "stackEmptyException.hpp"
#include "stackFullException.hpp"

template <class T>
stack<T>::stack() : m_current(0) //initialize current index to 0
{
	cout << "stack constructor" << endl;
}

template <class T>
stack<T>::stack(const stack<T>& s) : a(s.a), m_current(s.m_current)
{
}

template <class T>
stack<T>::~stack()
{
	cout << "stack destructor" << endl;
}

template <class T>
stack<T>& stack<T>::operator = (const stack<T>& s)
{
	if (this == &s)
		return *this;
	m_current = s.m_current;
	a = s.a;				//this should call the array assignment operator
	return *this;
}

template <class T>
int stack<T>::current()
{
	return m_current;
}

template <class T>
void stack<T>::push(T s)
{
	stackFullException err;
	try //put code in try catch block and use exception handlers
	{
		a.setElement(m_current, s);		//push the item s onto the stack 
		cout << "you just added " << a[m_current] <<" to place " << m_current << endl;
		m_current++;
	}
	catch(arrayException& q)
	{
		throw err;
	}
	
}

template <class T>
T& stack<T>::pop()
{
	stackEmptyException err;
	try
	{
		m_current--;
		return a[m_current];		
	}
	catch(arrayException& out)
	{
		m_current = 0;
		throw err;
	}

}


#endif