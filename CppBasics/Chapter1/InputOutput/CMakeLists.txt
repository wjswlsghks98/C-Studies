# CMake 프로그램의 최소 버전
cmake_minimum_required(VERSION 3.11)

# 프로젝트 정보
project(
    Chapter1
    VERSION 0.1
    DESCRIPTION "Testing"
    LANGUAGES CXX
    )

# cmake .. -G "Unix Makefiles" run like this if CMakeLists.txt is right inside the parent folder
# https://modoocode.com/332 참고하기
add_executable(program Prob3.cpp)