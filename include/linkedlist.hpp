#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <expected>

/**
* \typedef DSAPTR
* \brief Type alias for std::shared_ptr<T>
*/
template<class T>
using DSAPTR = std::shared_ptr<T>;

/**
* This is a template class represents a single element of the linked list, and it will be called "Node"
*/
template<class NType>
class Node {
public:
    NType data{}; /**< Stores the data for each node*/
    DSAPTR<Node<NType>> next = nullptr; /**< Stores the address of the next node*/

    /**
    * Default Constructor
    */
    Node() = default;
};


/**
* This is a template class that represents the linked list. It can take any basic C++ data type.
*/
template<class LLType>
class LinkedList {
private:
    DSAPTR<Node<LLType>> head;

    /**
    * A function that checks if the linked list is empty before putting a value at the end.
    * @param value - if the linked list is empty it will return an error message in the form of a std::string, if not I'll return the number 10.
    */
    std::expected<int, std::string> insertValueAtTheEndOfTheList(LLType value) {
        DSAPTR<Node<LLType>> newNode = std::make_shared<Node<LLType>>();
        if (head == nullptr) return std::unexpected("Linked List is empty, fill it first!");
        return 10;
    }

public:
    /**
    * Default Constructor
    */
    LinkedList() = default;

    /**
    * Inserts a value at the front of the linked list
    * @param value - the value that you want to pass to the front of the linked list
    */
    virtual LinkedList& insertAtFront(LLType value) {
        DSAPTR<Node<LLType>> newNode = std::make_shared<Node<LLType>>();
        newNode->data = value;
        newNode->next = head;

        head = newNode;
        return *this;
    }

    /**
    * A function that checks if the linked list is empty before putting a value at the end.
    * @param value - if the linked list is empty it will return an error message in the form of a std::string
    */
    virtual void insertAtEnd(LLType value) {
        auto InsertEndVar = insertValueAtTheEndOfTheList(value);

        if (InsertEndVar) {
            return;
        }
        else {
            std::cout << InsertEndVar.error();
        }
    }

    /**
    * Outputs the values in the linked list
    */
    virtual LinkedList& outputValues() {
        while (head) {
            std::cout << "Value: " << head->data << std::endl;
            head = head->next;
        }

        return *this;
    }

    /**
    * Default Destructor
    */
    virtual ~LinkedList() = default;

};


/**
* Basic example using a LinkedList<int>
*/
void ListExample();