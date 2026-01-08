cmake_minimum_required(VERSION 3.10)

# 1. Name your project
project(MyCppProject)

# 2. Set the standard (C++20 is good for modern dev)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 3. Enable Debug Symbols automatically
set(CMAKE_BUILD_TYPE Debug)

# 4. Define your executable
# Syntax: add_executable(TARGET_NAME SOURCE_FILES)
add_executable(my_app hello.cpp)