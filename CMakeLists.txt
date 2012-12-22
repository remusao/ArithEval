#Minimum version of CMake to build this project
cmake_minimum_required(VERSION 2.6)

# Declaration et nommage du projet
project(Bistro)

set(CMAKE_CXX_COMPILER  "clang++")
set(CMAKE_CXX_FLAGS_DEBUG "-std=c++11 -pedantic -Werror -Wall -D_DEBUG -g -O0 -Wno-shift-count-overflow")
set(CMAKE_CXX_FLAGS "-std=c++11 -pedantic -Werror -Wextra -Wall -O3 -march=native -Wno-shift-count-overflow")

#Defines subdirectory
add_subdirectory(src/)
