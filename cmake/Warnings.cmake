add_library(project_warnings INTERFACE)

if (MSVC)
    target_compile_options(project_warnings INTERFACE
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
    target_compile_options(project_warnings INTERFACE
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
