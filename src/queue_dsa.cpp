#include <queue>
#include <iostream>
#include <string>

#include "queue_dsa.hpp"

void UsingQueue() {
	std::queue<int> deez;
	//deez
}

void UsingQueue2() {
	std::cout << "\nQUEUE DATA STRUCTURE" << std::endl;

	 MyQueue<std::string> deez;
	 deez.push_back("David");
	 deez.push_back("Brume");
	 deez.push_back("Tare");
	 deez.push_back("Mom");
	 deez.push_back("Dad");

	 std::cout << "The first in the queue is " << deez.front_element() << std::endl;
	 std::cout << "The last in the queue is " << deez.last_element() << std::endl;

	 std::cout << "\nThere are " << deez.size() << " elements in the queue!" << std::endl;

	 std::cout << std::endl;

	 while (!deez.isEmpty()) {
		 std::cout << "The first in the queue right now is " << deez.front_element() << std::endl;
		 deez.popFront();
	 }
}