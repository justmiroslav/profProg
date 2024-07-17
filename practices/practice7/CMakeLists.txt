cmake_minimum_required(VERSION 3.27)
project(practice7)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/test/include)

add_executable(practice7 main.cpp src/Rectangle.cpp src/RectangleManager.cpp test/src/test.cpp)
