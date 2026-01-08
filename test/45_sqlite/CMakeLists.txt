cmake_minimum_required(VERSION 3.15)
project(sqlite_demonstration  CXX)

# cspell: ignore ftxui
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

execute_process(
    COMMAND conan install . --build=missing --profile=profile
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    RESULT_VARIABLE CONAN_RESULT
)
if(NOT ${CONAN_RESULT} EQUAL 0)
    message(FATAL_ERROR "Conan install failed with error code ${CONAN_RESULT}")
endif()

if(EXISTS "${CMAKE_BINARY_DIR}/Debug/generators/conan_toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_BINARY_DIR}/Debug/generators/conan_toolchain.cmake")
elseif(EXISTS "${CMAKE_SOURCE_DIR}/generators/conan_toolchain.cmake")
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/generators/conan_toolchain.cmake")
endif()


# include(${CMAKE_BINARY_DIR}/Debug/generators/conan_toolchain.cmake)

find_package(SQLite3 REQUIRED)
find_package(fmt REQUIRED)
 
add_executable(main main.cpp)
target_link_libraries(main
  PRIVATE SQLite::SQLite3
  PRIVATE fmt::fmt
)