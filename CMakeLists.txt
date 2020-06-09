cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(MyGraphik)
set(SOURCE_EXE "My Graphik.cpp" functions.cpp)
add_executable(MyGraphik ${SOURCE_EXE})