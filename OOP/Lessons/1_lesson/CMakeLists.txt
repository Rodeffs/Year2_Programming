cmake_minimum_required(VERSION 3.26)
project(lesson1)

set(CMAKE_CXX_STANDARD 17)

add_executable(lesson1 main.cpp
        figure.cpp
        figure.h)
