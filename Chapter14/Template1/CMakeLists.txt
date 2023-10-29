cmake_minimum_required(VERSION 3.11)

project(
    Chap14_1
    VERSION 0.1
    DESCRIPTION "Chapter 14-1"
    LANGUAGES CXX)

add_executable(runfile 
    src/BoundArrayMain.cpp)
target_compile_options(runfile PUBLIC -Wall -Werror)
target_include_directories(runfile PUBLIC ${CMAKE_SOURCE_DIR}/include)