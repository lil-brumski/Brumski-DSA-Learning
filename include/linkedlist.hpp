#pragma once

#include <iostream>
#include <memory>

/**
* This is a template class that represents the linked list. It can take any basic C++ data type.
* A linked list is a linear data structure, it can store multiple elements of the same data type. 
* Each node in a linked list contains the data item and a pointer to the next node.
*/
template<class LLType>
class LinkedList {
private:
    /**
    * This is a template class represents a single element of the linked list, and it will be called "Node"
    */
    template<class NType>
    class Node {
    public:
        NType data{}; /**< Stores the data for each node*/
        std::unique_ptr<Node<NType>> next = nullptr; /**< Stores the address of the next node*/

        /**
        * Default Constructor
        */
        Node() = default;
    };
private:
    std::unique_ptr<Node<LLType>> head;

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
    virtual LinkedList& insertAtFront(const LLType& value) {
        std::unique_ptr<Node<LLType>> newNode = std::make_unique<Node<LLType>>();
        newNode->data = value;
        newNode->next = std::move(head);

        head = std::move(newNode);
        return *this;
    }

    /**
    * Inserts a value at the end of the linked list
    * @param value - the value that you want to pass to the back of the linked list
    */
    virtual LinkedList& insertAtEnd(const LLType& value) {
        std::unique_ptr<Node<LLType>> newNode = std::make_unique<Node<LLType>>();
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = std::move(newNode);
            return *this;
        }

        Node<LLType>* lastNode = head.get();
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next.get();
        }
        lastNode->next = std::move(newNode);
        return *this;
    }

    /**
    * Outputs the values in the linked list
    */
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<LLType>& obj) {
        Node<LLType>* PRINT_node = obj.head.get();
        if (!obj.head) throw std::runtime_error("linked list is empty");
        
        os << "[";
        while (PRINT_node->next != nullptr) {
            std::cout << PRINT_node->data <<", ";
            PRINT_node = PRINT_node->next.get();
        }
        os << PRINT_node->data;
        PRINT_node = PRINT_node->next.get();
        os << "]";

        return os;
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