cmake_minimum_required(VERSION 4.0)
project(testRapidXml CXX)


find_package(rapidxml REQUIRED)
find_package(fmt REQUIRED)

add_executable(testt src/testt.cpp)
target_link_libraries(testt
    PRIVATE rapidxml::rapidxml
    PRIVATE fmt::fmt
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/src/f179486592.xml"
    "${CMAKE_CURRENT_BINARY_DIR}/f179486592.xml"
    COPYONLY
)
# spell: ignore testt rapidxml COPYONLY