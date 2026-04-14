cmake_minimum_required(VERSION 3.20)
project(LoadingProject CXX)

set(CMAKE_CXX_STANDARD 23)
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
find_package(indicators REQUIRED)

add_executable(LoadingProject test/LoadingProject.cpp)
target_link_libraries(LoadingProject PRIVATE fmt::fmt)
target_include_directories(LoadingProject PRIVATE ${CMAKE_SOURCE_DIR}/ext_library/LoadingAnimation)

add_executable(invoke_result test/invoke_result.cpp)

add_executable(indicator test/indicator.cpp)
target_include_directories(indicator PRIVATE ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(indicator PRIVATE indicators::indicators)