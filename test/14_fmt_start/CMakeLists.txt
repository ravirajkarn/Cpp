cmake_minimum_required(VERSION 3.10)

project("first_fmt_project" VERSION 0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Only set a default build type if it hasn't been specified on the command line
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'Debug' as none was specified.")
  
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build." FORCE)
  
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithPostInfo")
endif()

execute_process(
        COMMAND conan install . --build=missing
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE CONAN_RESULT
)
if(NOT ${CONAN_RESULT} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}") 
endif()

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

find_package(fmt)
add_executable(first_fmt_project fmt.cpp)
target_link_libraries(first_fmt_project PRIVATE fmt::fmt)