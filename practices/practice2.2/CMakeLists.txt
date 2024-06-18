cmake_minimum_required(VERSION 3.27)
project(practice2_2)

set(CMAKE_CXX_STANDARD 23)

add_executable(practice2_2 main.cpp
        include/ColorsMap.hpp
        include/ImageProcessor.hpp
        src/ImageProcessor.cpp
        src/ColorsMap.cpp)
