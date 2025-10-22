#include <vector>
#include <stdexcept>
#include "linkedlist.hpp"
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
    }
    else {
        argparse::ArgumentParser program("LinkedList", "1.0.1");

        std::vector<int> IntNumbers;
        program.add_argument("-i", "--int")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'i', int>()
            .store_into(IntNumbers);

        program.add_argument("-f", "--float")
            .nargs(argparse::nargs_pattern::at_least_one)
            .scan<'g', float>();

        std::vector<std::string> StringVessel;
        program.add_argument("-s", "--string")
            .nargs(argparse::nargs_pattern::at_least_one)
            .store_into(StringVessel);

        try {
            program.parse_args(argc, argv);
        }
        catch (const std::exception& error) {
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
                list_f.insertAtEnd(s);
            }

            std::cout << ansi(Color::green) << "\nSTART: Floats" << ansi() << std::endl;
            list_f.outputValues();
            std::cout << ansi(Color::green) << "STOP: Floats" << ansi() << std::endl;
        }
        /**
        *
        */
        if (program.is_used("--int")) {
            LinkedList<int> list_int;
            for (auto& s : IntNumbers) {
                list_int.insertAtEnd(s);
            }
            std::cout << ansi(Color::green) << "\nSTART: Integers" << ansi() << std::endl;
            list_int.outputValues();
            std::cout << ansi(Color::green) << "STOP: Integers" << ansi() << std::endl;
        }
        /**
        *
        */
        if (program.is_used("--string")) {
            LinkedList<std::string> list_str;
            for (auto& s : StringVessel) {
                list_str.insertAtEnd(s);
            }
            std::cout << ansi(Color::green) << "\nSTART: Strings" << ansi() << std::endl;
            list_str.outputValues();
            std::cout << ansi(Color::green) << "STOP: Strings" << ansi() << std::endl;
        }

    }

    return 0;
}