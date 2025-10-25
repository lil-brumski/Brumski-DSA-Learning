#pragma once

#include <iostream>
#include <memory>

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

public:
    /**
    * Default Constructor
    */
    LinkedList() = default;

    /**
    * Deleted copy constructor
    */
    LinkedList(const LinkedList<LLType>&) = delete;

    /**
    * Default Move constructor
    * @param other  - the object that you want to transfer ownership from
    */
    LinkedList(LinkedList<LLType>&& other) noexcept = default;

    /**
    * Default Copy assignment operator
    * Prevents assigning the values of existing LinkedList<T> objects to other objects.
    */
    virtual LinkedList<LLType>& operator=(const LinkedList<LLType>&) = delete;

    /**
    * Move assignment operator
    * @param other  - the object that you want to transfer ownership from
    */
    virtual LinkedList<LLType>& operator=(LinkedList<LLType>&& other) noexcept = default;

    /**
    * Default Destructor
    */
    virtual ~LinkedList() = default;

public:
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
    * Inserts a value at the end of the linked list
    * @param value - the value that you want to pass to the back of the linked list
    */
    virtual LinkedList& insertAtEnd(LLType value) {
        DSAPTR<Node<LLType>> newNode = std::make_shared<Node<LLType>>();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return *this;
        }

        DSAPTR<Node<LLType>> lastNode = head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        return *this;
    }

    /**
    * Outputs the values in the linked list
    */
    virtual LinkedList<LLType>& outputValues() {
        DSAPTR<Node<LLType>> PRINT_node = head;

        if (!PRINT_node) {
            std::cerr << "Object is null!" << std::endl;
            return *this;
        }

        while (PRINT_node) {
            std::cout << "Value: " << PRINT_node->data << std::endl;
            PRINT_node = PRINT_node->next;
        }

        return *this;
    }
};


/**
* Basic example using a LinkedList<int>
*/
void ListExample();

/**
* Basic example using a LinkedList<int>
*/
void ListExample2();