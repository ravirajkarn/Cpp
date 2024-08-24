cmake_minimum_required(VERSION 3.10)

project(testing_chrono)

find_package(fmt)
add_executable(test1 Date.cpp)
target_link_libraries(test1 PRIVATE fmt::fmt)