cmake_minimum_required(VERSION 3.27)
project(practice3_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(practice3_1 main.cpp
        include/UnitTests.hpp
        src/test.cpp
        src/Helpers.cpp)
