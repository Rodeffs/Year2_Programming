cmake_minimum_required(VERSION 3.26)
project(lesson2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lesson2 main.cpp
        Person.cpp
        Person.h
        Date.h
        Date.cpp)
