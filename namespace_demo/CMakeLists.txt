cmake_minimum_required(VERSION 3.21)
project(namespace_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(namespace_demo
        main.cpp
        test.cpp
        test.h
        test1.cpp
        test1.h)
