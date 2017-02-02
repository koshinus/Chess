cmake_minimum_required(VERSION 3.3)
project(test_chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp chess_class.hpp model.hpp create_figure.hpp)
add_executable(test_chess ${SOURCE_FILES})