cmake_minimum_required(VERSION 3.14)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

project(gtestexample)

add_subdirectory(src)
add_subdirectory(tests)
