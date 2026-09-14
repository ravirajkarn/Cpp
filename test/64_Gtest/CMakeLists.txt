cmake_minimum_required(VERSION 4.0)
project(binary_search CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
include(GoogleTest)

# add_executable(binary_search src/binary_search.cpp)

add_executable(leetCode_test test/leetCode_test.cpp)
target_link_libraries(leetCode_test GTest::gtest GTest::gtest_main)

add_executable(leetCode2_test test/test2.cpp)
target_link_libraries(leetCode2_test 
    PRIVATE
    GTest::gtest 
    GTest::gtest_main
    GTest::gmock
)

gtest_discover_tests(leetCode_test)