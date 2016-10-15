cmake_minimum_required(VERSION 3.2)
project(BinarySearch)
set (CMAKE_CXX_STANDARD 11)

add_executable(BinarySearch BinarySearch.cpp)
target_link_libraries(BinarySearch Common)
