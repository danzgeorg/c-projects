cmake_minimum_required(VERSION 4.0)
project(Coursework)

set(CMAKE_CXX_STANDARD 11)

add_executable(Coursework main.cpp
        module.h
        module.cpp
        grade.h
        grade.cpp)
