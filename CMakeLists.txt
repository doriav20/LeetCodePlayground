cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 23)

file(GLOB LeetCodePlayground_SRC
        "*.hpp"
        "*.tpp"
        "*.cpp"
)

add_executable(LeetCodePlayground ${LeetCodePlayground_SRC})
