cmake_minimum_required(VERSION 3.15)
project(Ashutosh_question CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
    COMMAND conan install . --build=missing --profile=profile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE conan_result
)
if(NOT ${conan_result} EQUAL 0)
    message(FATAL_ERROR "Conan install failed")
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)

add_executable(double_pyramid src/double_pyramid.cpp)

add_executable(box_pattern_animation src/box_pattern_animation.cpp)
target_link_libraries(box_pattern_animation PRIVATE fmt::fmt)

add_executable(box_pattern1 src/box_pattern1.cpp)
target_link_libraries(box_pattern1 PRIVATE fmt::fmt)

add_executable(box_pattern2 src/box_pattern2.cpp)
target_link_libraries(box_pattern2 PRIVATE fmt::fmt)