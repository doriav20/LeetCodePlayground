cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

message(STATUS "WARNINGS_AS_ERRORS: ${WARNINGS_AS_ERRORS}")

file(GLOB_RECURSE LeetCodePlayground_SRC
        CONFIGURE_DEPENDS
        src/*.cpp
)

add_executable(${PROJECT_NAME} ${LeetCodePlayground_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(Warnings)
target_link_libraries(${PROJECT_NAME} PRIVATE project_warnings)
