cmake_minimum_required(VERSION 3.30)

project(DataStructuresAndAlgorithms VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(deps/argparse)

add_executable(LinkedList linkedlist.cpp)

target_include_directories(LinkedList PRIVATE include)

target_link_libraries(LinkedList PRIVATE argparse)
