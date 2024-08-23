cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 23)

add_executable(LeetCodePlayground main.cpp
        TestCase.hpp
        TestsTool.hpp
        utils.hpp
        utils.cpp)
