cmake_minimum_required(VERSION 3.15)
project(Ch-16_Exercises CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(fmt REQUIRED)
add_executable(Q1 src/Q1.cpp)
target_link_libraries(Q1 PRIVATE fmt::fmt)
target_include_directories(Q1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q2 src/Q2.cpp)
target_link_libraries(Q2 PRIVATE fmt::fmt)
target_include_directories(Q2 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q3 src/Q3.cpp)
target_link_libraries(Q3 PRIVATE fmt::fmt)
target_include_directories(Q3 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q4 src/Q4.cpp)
# target_link_libraries(Q3 PRIVATE fmt::fmt)
# target_include_directories(Q3 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q5 src/Q5.cpp)
target_link_libraries(Q5 PRIVATE fmt::fmt)
target_include_directories(Q5 PRIVATE ${CMAKE_SOURCE_DIR}/include)