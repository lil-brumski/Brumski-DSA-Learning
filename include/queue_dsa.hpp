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
	/**
	* Inserts a value at the end of the queue
	* @param value - the value that you want to pass to the end of the queue
	*/
	virtual MyQueue<T>& push_back(const T& value) {
		DSAPTR<Node<T>> newNode = std::make_shared<Node<T>>();
		newNode->data = value;
		newNode->next = nullptr;

		if (!theFirst) {
			theFirst = newNode;
			return *this;
		}

		DSAPTR<Node<T>> lastNode = theFirst;
		while (lastNode->next != nullptr) {
			lastNode = lastNode->next;
		}
		lastNode->next = newNode;
		return *this;
	}

	/**
	* Prints out the front element in the queue
	*/
	virtual T front_element() {
		return theFirst->data;
	}

	/**
	* Prints out the last element in the queue
	*/
	virtual T last_element() {
		DSAPTR<Node<T>> temp = theFirst;
		while (temp->next != nullptr) {
			temp = temp->next;
		}

		return temp->data;
	}

	/**
	* Removes the first element in the queue
	*/
	virtual MyQueue<T>& popFront() {
		theFirst = theFirst->next;
		return *this;
	}

	/**
	* Returns true if the queue is empty
	*/
	virtual bool isEmpty() {
		if (theFirst) return false;
		else return true;

		return false;
	}

	virtual size_t size() {
		DSAPTR<Node<T>> temp = theFirst;
		size_t counter = 0;
		while (temp) {
			temp = temp->next;
			counter++;
		}

		return counter;
	}
};

void UsingQueue();