cmake_minimum_required(VERSION 3.2)
project("Common")
set (CMAKE_CXX_STANDARD 11)

add_library(Common STATIC
        include/Common/Common.hpp
        Common.cpp
)

target_include_directories(Common PUBLIC include)
