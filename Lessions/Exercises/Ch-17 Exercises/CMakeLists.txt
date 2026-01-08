cmake_minimum_required(VERSION 3.15)
project(Ch-17_Exercises CXX)

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
        COMMAND conan install . --build=missing --profile=profile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        RESULT_VARIABLE CONAN_RESULT
)
if(NOT ${CONAN_RESULT} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}") 
endif()

include(${CMAKE_BINARY_DIR}/Debug/generators/conan_toolchain.cmake)


# find_package(fmt REQUIRED)
add_executable(Q1 src/Q1.cpp)
# target_link_libraries(Q1 PRIVATE fmt::fmt)
target_include_directories(Q1 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q2 src/Q2.cpp)
# target_link_libraries(Q2 PRIVATE fmt::fmt)
target_include_directories(Q2 PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(Q3 src/Q3.cpp)
# target_link_libraries(Q3 PRIVATE fmt::fmt)
target_include_directories(Q3 PRIVATE ${CMAKE_SOURCE_DIR}/include)     