cmake_minimum_required(VERSION 3.15)
project(construct_word CXX)

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

add_executable(construct_word src/construct_word.cpp)
target_link_libraries(construct_word PRIVATE fmt::fmt)

add_executable(solution2 src/solution2.cpp)