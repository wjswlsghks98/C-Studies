# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

include(FetchContent)

FetchContent_Declare(matplotplusplus
        GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
        GIT_TAG origin/master) # or whatever tag you want

FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

project(EigenTest
VERSION 0.1
DESCRIPTION "Testing"
LANGUAGES CXX)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(testing testing.cpp)
target_link_libraries(testing PUBLIC matplot)
target_link_libraries(testing PUBLIC Eigen3)