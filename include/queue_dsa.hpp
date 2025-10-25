#pragma once
#include "linkedlist.hpp"

template<class T>
class MyQueue {
private:
	DSAPTR<Node<T>> theFirst; /**< Pointer to the first element of the queue*/
public:
	/**
	* Default Constructor
	*/
	MyQueue() = default;

	/**
	* Deleted copy constructor
	*/
	MyQueue(const MyQueue<T>&) = delete;

	/**
	* Default Move constructor
	* @param other  - the object that you want to transfer ownership from
	*/
	MyQueue(MyQueue<T>&& other) = default;

	/**
	* Deleted copy assignment operator
	*/
	MyQueue& operator=(const MyQueue<T>&) = delete;

	/**
	* Default Move assignment operator
	* @param other  - the object that you want to transfer ownership from
	*/
	MyQueue& operator=(MyQueue<T>&& other) = default;
public:
};

void UsingQueue();