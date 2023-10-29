cmake_minimum_required(VERSION 3.11)

project(
    Chap13
    VERSION 0.1
    DESCRIPTION "Chapter 13 Test"
    LANGUAGES CXX)

add_executable(runfile 
    Point.cpp
    BoundArrayMain.cpp)
target_compile_options(runfile PUBLIC -Wall -Werror)
target_include_directories(runfile PUBLIC ${CMAKE_SOURCE_DIR}/include)
