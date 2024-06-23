cmake_minimum_required(VERSION 3.27)
project(practice5_1)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/test/include)

add_executable(practice5_1 main.cpp src/MegaData.cpp src/MegaDataPool.cpp
        test/src/test.cpp)
