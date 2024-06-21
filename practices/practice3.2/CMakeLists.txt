cmake_minimum_required(VERSION 3.27)
project(practice3_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(practice3_2 main.cpp
        src/test.cpp
        include/Helpers.hpp
        src/Helpers.cpp)
