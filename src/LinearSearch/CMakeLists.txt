cmake_minimum_required(VERSION 3.2)
project(LinearSearch)
set (CMAKE_CXX_STANDARD 11)

add_executable(LinearSearch LinearSearch.cpp)
target_link_libraries(LinearSearch Common)
