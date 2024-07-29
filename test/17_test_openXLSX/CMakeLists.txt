cmake_minimum_required(VERSION 3.10)
project(Demo1 VERSION 0.0)

add_subdirectory(Examples)

# linking fmt libraries.
# find_package(fmt)
# target_link_libraries(Demo1 PRIVATE fmt::fmt)


# linking OpenXLSX libraries.
find_package(OpenXLSX)