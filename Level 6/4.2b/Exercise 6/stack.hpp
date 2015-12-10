#ifndef stack_HPP
#define stack_HPP

#include "array.hpp"

template <class T, int size> class stack
{
private:
	Array<T> a;		//array of type T
	int m_current;			//current index
public:
	stack<T, size>();					//default constructor
	stack<T, size>(const stack<T, size>& s);		//copy constructor
	virtual ~stack<T, size>();			//destructor

	stack<T, size>& operator = (const stack<T, size>& s); //assignment operator

	int current();

	void push(T s); //push function pushes the item to the end of the stack and increments index
	T& pop();			 //returns element of last position and decrements index
};

#endif

