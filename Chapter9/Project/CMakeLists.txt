cmake_minimum_required(VERSION 3.11)

project(
    Chap9Prj
    VERSION 0.1
    DESCRIPTION "Chapter 9 Project"
    LANGUAGES CXX)

add_executable(runfile 
    src/Account.cpp 
    src/AccountHandler.cpp
    src/BankingSystemMain.cpp 
    src/HighCreditAccount.cpp 
    src/NormalAccount.cpp)
target_compile_options(runfile PUBLIC -Wall -Werror)
target_include_directories(runfile PUBLIC ${CMAKE_SOURCE_DIR}/includes)
