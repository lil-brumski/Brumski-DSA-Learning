cmake_minimum_required(VERSION 3.30)

project(DataStructuresAndAlgorithms VERSION 1.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

if(CMAKE_BUILD_TYPE MATCHES "Release")
    message(STATUS "Building the Release Binary")
    set(CMAKE_BUILD_TYPE Release)
    set(CMAKE_EXE_LINKER_FLAGS "-s")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall
        -Wextra
        -Werror
        -Wpedantic
    )
endif()

add_subdirectory(deps/argparse)
add_subdirectory(deps/termcolor)

add_library(LinkedList STATIC "src/linkedlist.cpp")
add_library(Linked::List ALIAS LinkedList)
target_include_directories(LinkedList PUBLIC include)

add_library(MyStack STATIC "src/stack_dsa.cpp")
add_library(My::Stack ALIAS MyStack)
target_include_directories(MyStack PUBLIC include)

add_library(MyQueue STATIC "src/queue_dsa.cpp")
add_library(My::Queue ALIAS MyQueue)
target_include_directories(MyQueue PUBLIC include)

add_library(MyBinaryTree STATIC "src/binary_tree.cpp")
add_library(My::BinaryTree ALIAS MyBinaryTree)
target_include_directories(MyBinaryTree PUBLIC include)

add_executable(brumski_dsa "src/main.cpp" "appIcon.rc")
target_link_libraries(brumski_dsa PRIVATE argparse termcolor Linked::List My::Stack My::Queue My::BinaryTree)
