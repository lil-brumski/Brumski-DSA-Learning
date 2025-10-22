#pragma once

#include <linkedlist.hpp>

/**
* 
*/
void UsingStack();

/**
*
*/
template<class T>
class MyStack : public LinkedList<T> {
public:
	/**
	* Allows MyStack class to use the base class's constructors
	*/
	using LinkedList<T>::LinkedList; 

private:
	DSAPTR<Node<T>> myTop; /**< Pointer to the top element of the stack*/

public:
	/**
	* Returns the top element of the stack
	*/
	T Top() {

	}

	/**
	* Pushes a new element to the top of the stack
	*/
	MyStack<T> push_top() {
		return *this;
	}

	/**
	* Removes the top element of the stack
	*/
	MyStack<T> popTop() {
		return *this;
	}

	/**
	* Returns true if the stack is empty
	*/
	bool isEmpty() {
		if (myTop) return true;
		else return false;

		return false;
	}

	/**
	* Deleted copy assignment operator
	*/
	MyStack<T>& operator=(const MyStack<T>&) = delete;

	/**
	* Default move assignment operator
	*/
	MyStack<T>& operator=(MyStack<T>&&) = default;
};