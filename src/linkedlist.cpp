#include "linkedlist.hpp"
#include <utility>

void ListExample() {
    std::cout << "Begin" << std::endl;
    LinkedList<int> BIList;
    BIList.insertAtFront(1).insertAtFront(2).insertAtFront(3).outputValues();
    std::cout << "End" << std::endl;
}

void ListExample2() {
    std::cout << "\nLINKED LIST DATA STRUCTURE" << std::endl;

    std::cout << "BIList" << std::endl;
    LinkedList<int> BIList;
    BIList.insertAtEnd(1).insertAtEnd(2).insertAtEnd(3).outputValues();
   
    std::cout << "\nCopyObj1" << std::endl;
    LinkedList<int> CopyObj1 = std::move(BIList);
    //CopyObj1 = std::move(BIList);
    CopyObj1.outputValues();

    std::cout << "\nBIList" << std::endl;
    BIList.outputValues();

    std::cout << "\nBIList" << std::endl;
    BIList.insertAtFront(1);
    BIList.insertAtFront(2);
    BIList.insertAtFront(3);
    BIList.outputValues();
}