cmake_minimum_required(VERSION 3.27)
project(practice4_1)

set(CMAKE_CXX_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/test/include)

add_executable(practice4_1 main.cpp src/Pizza.cpp src/ConcretePizzaBuilder.cpp src/PizzaDirector.cpp
        src/Program.cpp test/src/PizzaTest.cpp test/src/MyTest.cpp test/src/ConcretePizzaBuilderTest.cpp
        test/src/PizzaDirectorTest.cpp)
