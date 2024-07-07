cmake_minimum_required(VERSION 3.10)

project("first_fmt_project" VERSION 0.0)


find_package(fmt)
add_executable(first_fmt_project fmt.cpp)
target_link_libraries(first_fmt_project PRIVATE fmt::fmt)