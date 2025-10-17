#include <iostream>
#include <type_traits>
#include <string>
#include <memory>
#include <expected>

template<class T>
using DSAPTR = std::shared_ptr<T>;

template<class NType>
class Node{
public:
    NType data{};
    DSAPTR<Node<NType>> next = nullptr;

    Node() = default;
};

template<class LLType>
class LinkedList{
private:
    DSAPTR<Node<LLType>> head;

    std::expected<int, std::string> __insertValueAtTheEndOfTheList(LLType value) {
        DSAPTR<Node<LLType>> newNode = std::make_shared<Node<LLType>>();
        if (head == nullptr) return std::unexpected("Linked List is empty, fill it first!");
        return 10;
    }

public:
    LinkedList() = default;

    virtual LinkedList& insertAtFront(LLType value) {
        DSAPTR<Node<LLType>> newNode = std::make_shared<Node<LLType>>();
        newNode->data = value;
        newNode->next = head;

        head = newNode;
        return *this;
    }

    virtual void insertAtEnd(LLType value) {
        auto InsertEndVar = __insertValueAtTheEndOfTheList(value);

        if (InsertEndVar) {
            return;
        }
        else {
            std::cout << InsertEndVar.error();
        }
    }

    virtual LinkedList& outputValues() {
        while (head) {
            std::cout << "Value: " << head->data << std::endl;
            head = head->next;
        }
       
        return *this;
    }

    virtual ~LinkedList() = default;
    
};

int main(int argc, char** argv){
    std::cout << "Begin" << std::endl;
    
    LinkedList<int> EmptyList;
    EmptyList.insertAtEnd(1);

    std::cout << std::endl;
    std::cout << std::endl;

    LinkedList<int> BIList;
    BIList.insertAtFront(3).insertAtFront(2).insertAtFront(1).outputValues();

    std::cout << std::endl;

    LinkedList<std::string> BSList;
    BSList.insertAtFront("Oghenebrume").insertAtFront("Tamaratare").insertAtFront("David").outputValues();

    std::cout << "End" << std::endl;

    return 0;
}