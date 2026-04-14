cmake_minimum_required(VERSION 3.15)
project(Permutation_and_combination CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(
        COMMAND conan install . --build=missing --profile=profile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE conan_result
        )
if(NOT ${conan_result} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code: ${conan_result}")
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt REQUIRED)

add_executable(formula src/Permutation_and_combination.cpp)
target_include_directories(formula PRIVATE ${PROJECT_SOURCE_DIR}/inc )
target_link_libraries(formula PRIVATE fmt::fmt)
