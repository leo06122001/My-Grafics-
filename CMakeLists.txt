cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(MyGraphik)
set(SOURCE_EXE "My Graphik.cpp" functions.cpp test.cpp)
add_executable(my_test test.cpp functions.cpp)
add_executable(MyGraphik "My Graphik.cpp" functions.cpp)
add_test(my_test my_test)
