cmake_minimum_required(VERSION 3.15)
# cspell: ignore keyhit
project(keyhit CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

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
find_package(GTest REQUIRED)
find_package(Curses REQUIRED)

# add_executable(keyhit src/keyhit.cpp)
# # cspell: ignore gtest ncurese
# target_link_libraries(  keyhit PUBLIC 
                    
#                         fmt::fmt 
#                         GTest::gtest
#                     )

add_executable(ncurese-test src/ncurese-test.cpp)
target_link_libraries(ncurese-test PUBLIC
                        fmt::fmt
                        GTest::gtest
                        Curses::Curses
                        )