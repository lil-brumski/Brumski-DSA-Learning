#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <expected>
#include <vector>

#include <argparse/argparse.hpp>

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
class Node{
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
class LinkedList{
private:
    DSAPTR<Node<LLType>> head;

    /**
    * A function that checks if the linked list is empty before putting a value at the end.
    * @param value - if the linked list is empty it will return an error message in the form of a std::string, if not I'll return the number 10.
    */
    std::expected<int, std::string> __insertValueAtTheEndOfTheList(LLType value) {
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
        auto InsertEndVar = __insertValueAtTheEndOfTheList(value);

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

int main(int argc, char** argv){

    if (argc == 1) {
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
    }
    else {
        argparse::ArgumentParser program("LinkedList", "1.0");

        std::vector<int> IntNumbers;
        program.add_argument("-i", "--int")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'i', int>()
            .store_into(IntNumbers);

        program.add_argument("-f", "--float")
            .nargs(argparse::nargs_pattern::any)
            .scan<'g', float>();

        std::vector<std::string> StringVessel;
        program.add_argument("-s", "--string")
            .nargs(argparse::nargs_pattern::at_least_one)
            .store_into(StringVessel);

        try {
            program.parse_args(argc, argv);
        }
        catch(const std::exception& error){
            std::cerr << error.what() << std::endl;
            std::cerr << program;
            return -1;
        }

        /**
        * 
        */
        if (program.is_used("--float")) {
            std::vector<float> FloatNumbers = program.get<std::vector<float>>("--float");
            LinkedList<float> list_f;
            for (auto& s : FloatNumbers) {
                list_f.insertAtFront(s);
            }

            std::cout << "\nSTART: Floats" << std::endl;
            list_f.outputValues();
            std::cout << "STOP: Floats" << std::endl;
        }
        /**
        *
        */
        if (program.is_used("--int")) {
            LinkedList<int> list_int;
            for (auto& s : IntNumbers) {
                list_int.insertAtFront(s);
            }
            std::cout << "\nSTART: Integers" << std::endl;
            list_int.outputValues();
            std::cout << "STOP: Integers" << std::endl;
        }
        /**
        *
        */
        if (program.is_used("--string")) {
            LinkedList<std::string> list_str;
            for (auto& s : StringVessel) {
                list_str.insertAtFront(s);
            }
            std::cout << "\nSTART: Strings" << std::endl;
            list_str.outputValues();
            std::cout << "STOP: Strings" << std::endl;
        }
        
    }

    return 0;
}