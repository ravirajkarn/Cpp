cmake_minimum_required(VERSION 3.31)
project(builder LANGUAGES CXX)

# Use C++17 standard (Good practice for modern apps)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the PkgConfig tool (helper to find libraries)
find_package(sciplot REQUIRED)

# Create the executable named "lyrics" from "main.cpp"
add_executable(graph main.cpp)

# Link the GTK4 libraries and include headers
target_link_libraries(graph PRIVATE sciplot::sciplot)


