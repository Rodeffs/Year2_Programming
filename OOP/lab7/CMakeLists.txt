# This is an example file that should be edited to fit the needs
# To build project using cmake type the following command in terminal: `cmake /path_to_source`
# It will build the project in the current folder. In the end type: `cmake --build .` to make it executable

cmake_minimum_required(VERSION 3.26) # cmake version, without it cmake simply won't run
project(lab7) # write the name of the project in the brackets

set(CMAKE_CXX_STANDARD 17) # setting the standard of C++, should be 17 by default

add_executable(lab7 IRepository.h IUserRepository.h main.cpp MemoryRepository.h MemoryUserRepository.h MemoryUserRepository.cpp User.h User.cpp) # all files used (including the project name) must be written in the brackets

