cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(Library VERSION ${PROJECT_VESRION})

configure_file(
        version.h.in 
        ${CMAKE_CURRENT_BINARY_DIR}/version.h
)

add_library(lib STATIC lib.cpp lib.h)

set_target_properties(
        lib PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        lib 
        PRIVATE 
        ${CMAKE_CURRENT_BINARY_DIR}
)

if (MSVC)
    target_compile_options(lib PRIVATE
        /W4
    )
else ()
    target_compile_options(lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()