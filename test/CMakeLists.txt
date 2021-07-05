cmake_minimum_required(VERSION 3.10)

project(test)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

add_executable(test_version_boost test_version_boost.cpp)
add_executable(test_version_gtest test_version_gtest.cpp)

set_target_properties(test_version_boost test_version_gtest PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version_boost PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(test_version_boost
    ${Boost_LIBRARIES}
    lib
)

target_link_libraries(
    test_version_gtest
    #${GTEST_BOTH_LIBRARIES}
    GTest::GTest GTest::Main
    lib
)

target_include_directories(test_version_gtest
    PRIVATE ${GTEST_INCLUDE_DIRS}
)

add_test(test_version_boost test_version_boost)
add_test(test_version_gtest test_version_gtest)

if (MSVC)
    target_compile_options(test_version_boost PRIVATE
        /W4
    )
    target_compile_options(test_version_gtest PRIVATE
        /W4
    )
else ()
    target_compile_options(test_version_boost PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version_gtest PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()