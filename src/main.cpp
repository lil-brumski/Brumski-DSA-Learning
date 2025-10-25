#include <vector>
#include <stdexcept>
#include <string>

#include "linkedlist.hpp"
#include "stack_dsa.cpp"
#include "queue_dsa.cpp"

#include <argparse/argparse.hpp>

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


/**
* Contains constants that will allow the text in the command line to have colours other than the default one.
*/

enum class Color {
    red, /**< Will display the colour red*/
    green, /**< Will display the colour green*/
    yellow, /**< Will display the colour yellow*/
    reset /**< Will display the default command line colour*/
};

/**
* \brief View-only string function
* @param c - the enum constant containing the ANSI value that you want displayed.
*/
constexpr std::string_view ansi(Color c = Color::reset) {
    switch (c) {
    case Color::red: return "\033[31m";
    case Color::reset: return "\033[0m";
    case Color::green: return "\033[32m";
    case Color::yellow: return "\033[33m";
    }
    return "\033[0m";
}

int main(int argc, char** argv) {

    if (argc == 1) {
        //ListExample();
        ListExample2();
        //UsingStack();
        UsingStack2();
        //UsingQueue();
        UsingQueue2();
    }
    else {
        argparse::ArgumentParser program("LinkedList", "1.2");

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

        try {
            program.parse_args(argc, argv);
        }
        catch (const std::exception& error) {
            std::cerr << error.what() << std::endl;
            std::cerr << program;
            return -1;
        }

        /**
        * For checking if --floatll and/or --floatst is/are passed as arguments
        */
        if (program.is_used("--floatll") || program.is_used("--floatst")) {
            if (program.is_used("--floatll")) {
                std::vector<float> FloatNumbers = program.get<std::vector<float>>("--floatll");
                LinkedList<float> list_f;
                for (auto& s : FloatNumbers) {
                    list_f.insertAtEnd(s);
                }

                std::cout << ansi(Color::green) << "\nSTART (linked list): Floats" << ansi() << std::endl;
                list_f.outputValues();
                std::cout << ansi(Color::green) << "STOP: Floats" << ansi() << std::endl;
            }
            if(program.is_used("--floatst")){
                std::vector<float> FDEC = program.get<std::vector<float>>("--floatst");
                MyStack<float> obj_f;
                for (auto& s : FDEC) {
                    obj_f.push_top(s);
                }

                std::cout << ansi(Color::green) << "\nSTART (stack): Floats" << ansi() << std::endl;
                UsingStack3(obj_f);
                std::cout << ansi(Color::green) << "STOP: Floats" << ansi() << std::endl;
            }
        }

        /**
        * For checking if --intll and/or --intst is/are passed as arguments
        */
        if (program.is_used("--intll") || program.is_used("--intst")) {
            if (program.is_used("--intll")) {
                LinkedList<int> list_int;
                for (auto& s : IntNumbers) {
                    list_int.insertAtEnd(s);
                }
                std::cout << ansi(Color::green) << "\nSTART (linked list): Integers" << ansi() << std::endl;
                list_int.outputValues();
                std::cout << ansi(Color::green) << "STOP: Integers" << ansi() << std::endl;
            }
            if(program.is_used("--intst")) {
                MyStack<int> obj_int;
                for (auto& s : SINT) {
                    obj_int.push_top(s);
                }
                std::cout << ansi(Color::green) << "\nSTART (stack): Integers" << ansi() << std::endl;
                UsingStack3(obj_int);
                std::cout << ansi(Color::green) << "STOP: Integers" << ansi() << std::endl;
            }
        }

        /**
        * For checking if --stringll and/or --stringst is/are passed as arguments
        */
        if (program.is_used("--stringll") || program.is_used("--stringst")) {
            if (program.is_used("--stringll")) {
                LinkedList<std::string> list_str;
                for (auto& s : StringVessel) {
                    list_str.insertAtEnd(s);
                }
                std::cout << ansi(Color::green) << "\nSTART (linked list): Strings" << ansi() << std::endl;
                list_str.outputValues();
                std::cout << ansi(Color::green) << "STOP: Strings" << ansi() << std::endl;
            }
            if(program.is_used("--stringst")) {
                MyStack<std::string> obj_str;
                for (auto& s : SCHAR) {
                    obj_str.push_top(s);
                }
                std::cout << ansi(Color::green) << "\nSTART (stack): Strings" << ansi() << std::endl;
                UsingStack3(obj_str);
                std::cout << ansi(Color::green) << "STOP: Strings" << ansi() << std::endl;
            }
        }

    }

    return 0;
}