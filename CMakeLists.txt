cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(MyGraphik)
set(SOURCE_EXE "My Graphik.cpp" functions.cpp test.cpp)
add_executable(MyGraphik "My Graphik.cpp")
add_executable(test test.cpp)
