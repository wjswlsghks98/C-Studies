cmake_minimum_required(VERSION 3.11)
project(test)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(test ${SOURCES})