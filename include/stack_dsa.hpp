#pragma once

#include "linkedlist.hpp"

/**
* Basic example using a std::stack<int>
*/
void UsingStack();

/**
* Basic example using a MyStack<int>
*/
void UsingStack2();

/**
* This is a template class that represents the stack data structure. It can take any basic C++ data type.
*/
template<class T>
class MyStack {
public:
	/**
	* Default Constructor
	*/
	MyStack() = default;

	/**
	* Deleted copy constructor
	*/
	MyStack(const MyStack<T>&) = delete;

	/**
	* Default Move constructor
	* @param other  - the object that you want to transfer ownership from
	*/
	MyStack(MyStack<T>&& other) noexcept = default;

	/**
	* Deleted copy assignment operator
	*/
	MyStack<T>& operator=(const MyStack<T>&) = delete;

	/**
	* Default Move assignment operator
	* @param other  - the object that you want to transfer ownership from
	*/
	MyStack<T>& operator=(MyStack<T>&& other) noexcept = default;
private:
	DSAPTR<Node<T>> myTop; /**< Pointer to the top element of the stack*/

public:
	/**
	* Returns the top element of the stack
	*/
	virtual T Top() {
		return myTop->data;
	}

	/**
	* Pushes a new element to the top of the stack
	* @param value - The value you want to pass to the top of the stack
	*/
	virtual MyStack<T>& push_top(const T& value) {
		DSAPTR<Node<T>> newNode = std::make_shared<Node<T>>();
		newNode->data = value;
		newNode->next = myTop;
		myTop = newNode;

		return *this;
	}

	/**
	* Removes the top element of the stack
	*/
	virtual MyStack<T>& popTop() {
		myTop = myTop->next;
		return *this;
	}

	/**
	* Returns true if the stack is empty
	*/
	virtual bool isEmpty() {
		if (myTop) return false;
		else return true;

		return false;
	}
};

/**
* Basic example using a MyStack<T>
* @param object1 - a reference to the MyStack<T> object we want to work on
*/
template<class T>
void UsingStack3(MyStack<T>& object1) {
	while (!object1.isEmpty()) {
		std::cout << "The top element is " << object1.Top() << std::endl;
		object1.popTop();
	}
}