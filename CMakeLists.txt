cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE LeetCodePlayground_SRC
        "src/*.hpp"
        "src/*.tpp"
        "src/*.cpp"
)

add_executable(LeetCodePlayground ${LeetCodePlayground_SRC})
