cmake_minimum_required(VERSION 3.15)
project(fileIO CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(file file.cpp)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/data.txt"
    "${CMAKE_CURRENT_BINARY_DIR}/data.txt"
    COPYONLY
)