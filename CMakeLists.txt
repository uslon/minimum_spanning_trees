cmake_minimum_required(VERSION 3.14)
project(MST)

set(CMAKE_CXX_STANDARD 14)

add_executable(MST main.cpp
        test.cpp
        mst.cpp
        mst.h)

add_subdirectory(googletest)
target_link_libraries(MST gtest gtest_main)
