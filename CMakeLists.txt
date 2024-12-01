cmake_minimum_required(VERSION 3.30)
project(aoc2024)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
include(CTest)
include(cmake/CPM.cmake)
include(cmake/fetch-googletest.cmake)
enable_testing()

add_subdirectory(src)
add_subdirectory(test)