# filepath: /d:/useful/Code/C++/Test/26_storing_date/CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(storedate CXX)

# Showing the chef where conan's kitchen is located.
include(${CMAKE_BINARY_DIR}/Release/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)

add_executable(storedate src/storedate.cpp)

target_link_libraries(storedate PRIVATE fmt::fmt)