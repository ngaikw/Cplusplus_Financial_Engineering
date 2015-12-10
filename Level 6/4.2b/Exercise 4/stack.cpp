#ifndef stack_CPP
#define stack_CPP

#include "stack.hpp"

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
	a.setElement(m_current, s);		//push the item s onto the stack 
	m_current++;					//increment index
}

template <class T>
T& stack<T>::pop()
{

	m_current--;
	return a[m_current];			//now the index can b changed 
}


#endif