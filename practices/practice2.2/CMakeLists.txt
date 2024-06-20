cmake_minimum_required(VERSION 3.27)
project(practice2_2)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(practice2_2 main.cpp src/ImageProcessor.cpp)
