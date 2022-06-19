cmake_minimum_required(VERSION 3.10)

project(main)

add_executable(helloworld main.cpp)

set_target_properties(
        helloworld PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        helloworld
        PRIVATE
        ${CMAKE_SOURCE_DIR}/lib
)

target_link_libraries(helloworld lib)

if (MSVC)
    target_compile_options(helloworld PRIVATE
            /W4
            )
else ()
    target_compile_options(helloworld PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif()