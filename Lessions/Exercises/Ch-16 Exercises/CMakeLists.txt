cmake_minimum_required(VERSION 3.15)
project(Ch-16_Exercises CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
        COMMAND conan install . --build=missing --profile=profile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE CONAN_RESULT
)
if(NOT ${CONAN_RESULT} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}") 
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)

add_executable(Q1 src/Q1.cpp)
target_link_libraries(Q1 PRIVATE fmt::fmt)
target_include_directories(Q1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q2 src/Q2.cpp)
target_link_libraries(Q2 PRIVATE fmt::fmt)
target_include_directories(Q2 PRIVATE ${CMAKE_SOURCE_DIR}/include)