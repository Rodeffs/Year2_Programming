cmake_minimum_required(VERSION 3.26)
project(practice1)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice1 main.cpp
        SolveIntegral.cpp
        SolveIntegral.h
        TrapezoidMethod.cpp
        TrapezoidMethod.h
        SimpsonMethod.cpp
        SimpsonMethod.h
)
