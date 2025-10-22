#include <stack_dsa.hpp>
#include <stack>

void UsingStack() {
	std::stack<int> myStackInt;
	myStackInt.push(20);
	myStackInt.push(40);
	myStackInt.push(60);
	myStackInt.push(80);
	myStackInt.push(100);

	while (!myStackInt.empty()) {
		std::cout << "The top element from std::stack<int> is " << myStackInt.top() << std::endl;
		myStackInt.pop();
	}
}

void UsingStack2() {
	MyStack<int> object1;
	object1.push_top(45);
	object1.push_top(75);
	object1.push_top(105);
	object1.push_top(135);
	object1.push_top(165);

	while (!object1.isEmpty()) {
		std::cout << "The top element from MyStack<int> is " << object1.Top() << std::endl;
		object1.popTop();
	}
}