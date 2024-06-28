cmake_minimum_required(VERSION 3.21)
project(virtual_override_demo)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(base_syntax
        main.cpp)
