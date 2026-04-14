cmake_minimum_required(VERSION 3.31)
project(Music_Player CXX)

# # cspell: ignore ftxui 
# set(CMAKE_CXX_STANDARD 23)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS ON)



if(NOT BUILD_SHARED_LIBS)
  add_definitions(-DTAGLIB_STATIC)
endif()

find_package(taglib REQUIRED) #     cspell: ignore taglib
find_package(fmt REQUIRED)

add_executable(extraction src/extraction.cpp)
target_link_libraries(extraction 
                        PRIVATE taglib::taglib
                        PRIVATE fmt::fmt
)