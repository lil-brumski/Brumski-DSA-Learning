cmake_minimum_required(VERSION 3.30)

project(DataStructuresAndAlgorithms VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(deps/argparse)

add_library(LinkedList STATIC "src/linkedlist.cpp")
add_library(Linked::List ALIAS LinkedList)
target_include_directories(LinkedList PUBLIC include)

add_executable(brumski_dsa "src/main.cpp")
target_link_libraries(brumski_dsa PRIVATE argparse Linked::List)
