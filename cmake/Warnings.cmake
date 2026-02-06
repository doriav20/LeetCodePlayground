add_library(project_warnings INTERFACE)

if (MSVC)
    target_compile_options(project_warnings INTERFACE
            /W4                 # High warning level
            /permissive-        # Enforce standard conformance
            /w14242             # 'identifier': conversion, possible loss of data
            /w14254             # 'operator': conversion, possible loss of data
            /w14263             # 'function': member function does not override
            /w14265             # 'class': virtual destructor missing
            /w14287             # unsigned/negative mismatch
            /we4289             # loop variable used outside scope
            /w14296             # expression always false
    )

    if (WARNINGS_AS_ERRORS)
        target_compile_options(project_warnings INTERFACE /WX)
    endif ()

else ()
    target_compile_options(project_warnings INTERFACE
            -Wall
            -Wextra
            -Wpedantic
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

    if (WARNINGS_AS_ERRORS)
        target_compile_options(project_warnings INTERFACE -Werror)
    endif ()

endif ()
