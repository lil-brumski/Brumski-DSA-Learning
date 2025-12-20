#include <vector>
#include <string>

#include "linkedlist.hpp"
#include "stack_dsa.cpp"
#include "queue_dsa.cpp"
#include "map_dsa.hpp"
#include "binary_tree.hpp"

#include <argparse/argparse.hpp>
#include <termcolor/termcolor.hpp>

#if defined(_WIN32)
	#pragma message("Target: Windows")
#elif defined(__ANDROID__)
	#pragma message("Target: Android")
#elif defined(__APPLE__)
	#pragma message("Target: macOS/iOS")
#elif defined(__linux__)
	#pragma message("Target: Linux")
#else
	#pragma message("Target: Unknown Platform")
#endif

#if defined(_MSC_VER)
	#pragma message("Compiler: MSVC detected")
#elif defined(__clang__)
	#pragma message("Compiler: Clang detected")
#elif defined(__GNUC__)
	#pragma message("Compiler: GCC detected")
#else 
	#pragma message("Compiler: Unknown Compiler")
#endif

int main(int argc, char** argv) {

    if (argc == 1) {
        //ListExample();
        ListExample2();
        //UsingStack();
        UsingStack2();
        //UsingQueue();
        UsingQueue2();
        //UsingMap();
        UsingMap2();
        UsingBST();
    }
    else {
        argparse::ArgumentParser program("LinkedList", "1.4");

        //For linked lists
        std::vector<int> IntNumbers;
        program.add_argument("-il", "--intll")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'i', int>()
            .store_into(IntNumbers);

        program.add_argument("-fl", "--floatll")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'g', float>();

        std::vector<std::string> StringVessel;
        program.add_argument("-sl", "--stringll")
            .nargs(argparse::nargs_pattern::at_least_one)
            .store_into(StringVessel);

        //For stack data structure
        std::vector<int> SINT;
        program.add_argument("-is", "--intst")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'i', int>()
            .store_into(SINT);

        program.add_argument("-fs", "--floatst")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'g', float>();

        std::vector<std::string> SCHAR;
        program.add_argument("-ss", "--stringst")
            .nargs(argparse::nargs_pattern::at_least_one)
            .store_into(SCHAR);

        //For queue data structure
        std::vector<int> QINT;
        program.add_argument("-iq", "--intqu")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'i', int>()
            .store_into(QINT);

        program.add_argument("-fq", "--floatqu")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'g', float>();

        std::vector<std::string> QCHAR;
        program.add_argument("-sq", "--stringqu")
            .nargs(argparse::nargs_pattern::at_least_one)
            .store_into(QCHAR);

        try {
            program.parse_args(argc, argv);
        }
        catch (const std::exception& error) {
            std::cerr << error.what() << std::endl;
            std::cerr << program;
            return -1;
        }

        /**
        * For checking if --floatll and/or --floatst and/or --floatqu is/are passed as arguments
        */
        if (program.is_used("--floatll") || program.is_used("--floatst") || program.is_used("--floatqu")) {
            if (program.is_used("--floatll")) {
                std::vector<float> FloatNumbers = program.get<std::vector<float>>("--floatll");
                LinkedList<float> list_f;
                for (auto& s : FloatNumbers) {
                    list_f.insertAtEnd(s);
                }

                std::cout << termcolor::green << "\nSTART (linked list): Floats" << termcolor::reset << std::endl;
                std::cout << list_f << std::endl;
                std::cout << termcolor::green << "STOP: Floats" << termcolor::reset << std::endl;
            }
            if(program.is_used("--floatst")){
                std::vector<float> FDEC = program.get<std::vector<float>>("--floatst");
                MyStack<float> obj_f;
                for (auto& s : FDEC) {
                    obj_f.push_top(s);
                }

                std::cout << termcolor::green << "\nSTART (stack): Floats" << termcolor::reset << std::endl;
                UsingStack3(obj_f);
                std::cout << termcolor::green << "STOP: Floats" << termcolor::reset << std::endl;
            }
            if (program.is_used("--floatqu")) {
                std::vector<float> FQ = program.get<std::vector<float>>("--floatqu");
                MyQueue<float> myFQ;
                for (auto& s : FQ) {
                    myFQ.push_back(s);
                }

                std::cout << termcolor::green << "\nSTART (queue): Floats" << termcolor::reset << std::endl;
                UsingQueue3(myFQ);
                std::cout << termcolor::green << "STOP: Floats" << termcolor::reset << std::endl;
            }
        }

        /**
        * For checking if --intll and/or --intst and/or --intqu is/are passed as arguments
        */
        if (program.is_used("--intll") || program.is_used("--intst") || program.is_used("--intqu")) {
            if (program.is_used("--intll")) {
                LinkedList<int> list_int;
                for (auto& s : IntNumbers) {
                    list_int.insertAtEnd(s);
                }
                std::cout << termcolor::green << "\nSTART (linked list): Integers" << termcolor::reset << std::endl;
                std::cout << list_int << std::endl;
                std::cout << termcolor::green << "STOP: Integers" << termcolor::reset << std::endl;
            }
            if(program.is_used("--intst")) {
                MyStack<int> obj_int;
                for (auto& s : SINT) {
                    obj_int.push_top(s);
                }
                std::cout << termcolor::green << "\nSTART (stack): Integers" << termcolor::reset << std::endl;
                UsingStack3(obj_int);
                std::cout << termcolor::green << "STOP: Integers" << termcolor::reset << std::endl;
            }
            if (program.is_used("--intqu")) {
                MyQueue<int> myIQ;
                for (auto& s : QINT) {
                    myIQ.push_back(s);
                }
                std::cout << termcolor::green << "\nSTART (queue): Integers" << termcolor::reset << std::endl;
                UsingQueue3(myIQ);
                std::cout << termcolor::green << "STOP: Integers" << termcolor::reset << std::endl;
            }
        }

        /**
        * For checking if --stringll and/or --stringst and/or --stringqu is/are passed as arguments
        */
        if (program.is_used("--stringll") || program.is_used("--stringst") || program.is_used("--stringqu")) {
            if (program.is_used("--stringll")) {
                LinkedList<std::string> list_str;
                for (auto& s : StringVessel) {
                    list_str.insertAtEnd(s);
                }
                std::cout << termcolor::green << "\nSTART (linked list): Strings" << termcolor::reset << std::endl;
                std::cout << list_str << std::endl;
                std::cout << termcolor::green << "STOP: Strings" << termcolor::reset << std::endl;
            }
            if(program.is_used("--stringst")) {
                MyStack<std::string> obj_str;
                for (auto& s : SCHAR) {
                    obj_str.push_top(s);
                }
                std::cout << termcolor::green << "\nSTART (stack): Strings" << termcolor::reset << std::endl;
                UsingStack3(obj_str);
                std::cout << termcolor::green << "STOP: Strings" << termcolor::reset << std::endl;
            }
            if (program.is_used("--stringqu")) {
                MyQueue<std::string> mySQ;
                for (auto& s : QCHAR) {
                    mySQ.push_back(s);
                }
                std::cout << termcolor::green << "\nSTART (queue): Strings" << termcolor::reset << std::endl;
                UsingQueue3(mySQ);
                std::cout << termcolor::green << "STOP: Strings" << termcolor::reset << std::endl;
            }
        }

    }

    return 0;
}
