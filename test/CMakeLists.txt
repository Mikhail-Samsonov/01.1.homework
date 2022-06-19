cmake_minimum_required(VERSION 3.10)

project(test)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake")
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE
        conanfile.txt
        BASIC_SETUP
        CMAKE_TARGETS
        BUILD missing)

include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(version_boost version_boost.cpp)
target_link_libraries(version_boost boost_unit_test_framework lib)
target_include_directories(version_boost PRIVATE ${CMAKE_SOURCE_DIR}/lib)
add_test(NAME boost_test COMMAND version_boost)


configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/test/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/test/googletest-src
        ${CMAKE_BINARY_DIR}/test/googletest-build)


add_executable(version_gtest version_gtest.cpp)
target_link_libraries(version_gtest gtest_main lib)
target_include_directories(version_gtest PRIVATE ${CMAKE_SOURCE_DIR}/lib)
add_test(NAME gtest_test COMMAND version_gtest)


if (MSVC)
    target_compile_options(version_boost PRIVATE /W4)
    target_compile_options(version_gtest PRIVATE /W4)
else ()
    target_compile_options(version_boost PRIVATE -Wall -Wextra -pedantic -Werror)
    target_compile_options(version_gtest PRIVATE -Wall -Wextra -pedantic -Werror)
endif ()