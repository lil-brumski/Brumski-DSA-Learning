#include <iostream>
#include <type_traits>
#include <memory>

template<class T>
using DSAPTR = std::shared_ptr<T>;

template<class NType>
class Node{
public:
    NType data;
    DSAPTR<Node<NType>> next;

    Node(){
        this->data = 0;
        next = nullptr;
    }
};

template<class LLType>
class LinkedList{
public:
    DSAPTR<Node<LLType>> head;

    LinkedList() = delete;
    LinkedList(int zero){
        head = nullptr;
    }
};

void print_list(DSAPTR<Node<int>>& head) {
    while (head) {
        std::cout << "Value: " << head->data << std::endl;
        head = head->next;
    }
}

void FakeMain() {
    DSAPTR<Node<int>> head = std::make_shared<Node<int>>();
    DSAPTR<Node<int>> second = std::make_shared<Node<int>>();
    DSAPTR<Node<int>> third = std::make_shared<Node<int>>();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = nullptr;

    print_list(head);
}

int main(int argc, char** argv){
    LinkedList<int> LL(0);

    std::cout << "Begin" << std::endl;
    FakeMain();
    std::cout << "End" << std::endl;

    return 0;
}