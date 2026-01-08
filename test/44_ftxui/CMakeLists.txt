cmake_minimum_required(VERSION 3.15)
project(loading CXX)

# cspell: ignore ftxui
set(CMAKE_CXX_STANDARD 23)
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

find_package(ftxui REQUIRED)
 
add_executable(main src/screen.cpp)
target_link_libraries(main
  PRIVATE ftxui::screen
)

add_executable(same src/dom.cpp)
target_link_libraries(main
  PRIVATE ftxui::screen
)