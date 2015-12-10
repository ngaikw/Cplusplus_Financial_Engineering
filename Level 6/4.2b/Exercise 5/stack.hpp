#ifndef stack_HPP
#define stack_HPP

#include "array.hpp"

template <class T> class stack
{
private:
	Array<T> a;		//array of type T
	int m_current;  //current index
public:
	stack<T>();					//default constructor
	stack<T>(const stack<T>& s);		//copy constructor
	virtual ~stack<T>();			//destructor

	stack<T>& operator = (const stack<T>& s); //assignment operator

	int current();

	void push(T s); //push function pushes the item to the end of the stack and increments index
	T& pop();			 //returns element of last position and decrements index
};

#endif

