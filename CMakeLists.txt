cmake_minimum_required(VERSION 3.29)
project(AISD)

set(CMAKE_CXX_STANDARD 20)

add_executable(AISD main.cpp
        LinkedList.cpp
        LinkedList.h
        Stack.cpp
        Stack.h)
