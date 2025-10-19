#include "linkedlist.hpp"

void ListExample() {
    std::cout << "Begin" << std::endl;
    LinkedList<int> BIList;
    BIList.insertAtFront(3).insertAtFront(2).insertAtFront(1).outputValues();
    std::cout << "End" << std::endl;
}