cmake_minimum_required(VERSION 3.15)
project(ch-15exercises CXX)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

include_directories(include)
add_executable(Q1 src/Q1.cpp)

find_package(fmt REQUIRED)
add_executable(Q2 src/Q2.cpp)
target_link_libraries(Q2 PRIVATE fmt::fmt)

add_executable(Q3 src/Q3.cpp)
target_link_libraries(Q3 PRIVATE fmt::fmt)