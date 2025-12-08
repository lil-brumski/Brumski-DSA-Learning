#pragma once
#include <memory>
#include <iostream>

/**
* This is a template class that represents the queue data structure.
* It can take any basic C++ data type.
* It uses the First In First Out (FIFO) principle.
*/
template<class T>
class MyQueue {
private:
	/**
	* This is a template class that represents a single element of a queue, and it will be called "Node"
	*/
	template<class NType>
	class Node {
	public:
		NType data{}; /**< Stores the data for each node*/
		std::shared_ptr<Node<NType>> next = nullptr; /**< Stores the address of the next node*/

		/**
		* Default Constructor
		*/
		Node() = default;
	};
private:
	std::shared_ptr<Node<T>> theFirst; /**< Pointer to the first element of the queue*/
	std::shared_ptr<Node<T>> theRear; /**< Pointer to the last element of the queue*/
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
		std::shared_ptr<Node<T>> newNode = std::make_unique<Node<T>>();
		newNode->data = value;
		newNode->next = nullptr;

		if (!theFirst) {
			theFirst = theRear = newNode;
			return *this;
		}
		else {
			theRear->next = newNode;
			theRear = newNode;
			return *this;
		}

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
		Node<T>* temp = theFirst.get();
		while (temp->next != nullptr) {
			temp = temp->next.get();
		}

		return temp->data;
	}

	/**
	* Removes the first element in the queue
	*/
	virtual T popFront() {
		if (theFirst == nullptr) throw std::runtime_error("cannot dequeue empty queue");
		T data = theFirst->data;
		theFirst = theFirst->next;
		if (theFirst == nullptr) theRear = nullptr;

		return data;
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
		Node<T>* temp = theFirst.get();
		size_t counter = 0;
		while (temp) {
			temp = temp->next.get();
			counter++;
		}

		return counter;
	}
};

/**
* Incomplete std::queue example
*/
void UsingQueue();

/**
* Example demonstrating the use of MyQueue<T>
*/
void UsingQueue2();

/**
* For accessing the elements of a MyQueue<T> object
* @param deez - the MyQueue<T> object, no copy is made, uses a reference instead
*/
template<class T>
void UsingQueue3(MyQueue<T>& deez) {
	while (!deez.isEmpty()) {
		std::cout << "The first in the queue right now is " << deez.front_element() << std::endl;
		deez.popFront();
		std::cout << "The first has been popped!" << std::endl;
	}
}