cmake_minimum_required(VERSION 3.26)
project(LeetCodePlayground)

set(CMAKE_CXX_STANDARD 23)

file(GLOB_RECURSE LeetCodePlayground_SRC
        CONFIGURE_DEPENDS
        src/*.cpp
)

add_executable(${PROJECT_NAME} ${LeetCodePlayground_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4                 # High warning level
            /WX                 # Warnings as errors
            /permissive-        # Enforce standard conformance
            /w14242             # 'identifier': conversion, possible loss of data
            /w14254             # 'operator': conversion, possible loss of data
            /w14263             # 'function': member function does not override
            /w14265             # 'class': virtual destructor missing
            /w14287             # unsigned/negative mismatch
            /we4289             # loop variable used outside scope
            /w14296             # expression always false
    )
else ()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
            -Wshadow
            -Wconversion
            -Wsign-conversion
            -Wold-style-cast
            -Woverloaded-virtual
            -Wnon-virtual-dtor
            -Wnull-dereference
            -Wdouble-promotion
            -Wformat=2
            -Wimplicit-fallthrough
            -Wmisleading-indentation
            -Wduplicated-cond
            -Wduplicated-branches
            -Wlogical-op
            -Wuseless-cast
    )
endif ()
