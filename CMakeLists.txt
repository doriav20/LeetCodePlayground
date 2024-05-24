cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 17)

add_executable(LeetCodePlayground main.cpp
        TestCase.h
        TestsTool.h
        utils.h
        utils.cpp)
