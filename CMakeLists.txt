cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE LeetCodePlayground_SRC
        CONFIGURE_DEPENDS
        src/*.cpp
)

add_executable(${PROJECT_NAME} ${LeetCodePlayground_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)
