cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(MyGraphik)
set(SOURCE_EXE "My Graphik.cpp" functions.cpp test.cpp)
add_executable(test test.cpp functions.cpp)
add_executable(MyGraphik "My Graphik.cpp" functions.cpp)
target_link_libraries(proj_test PUBLIC doctest::doctest default)
target_link_libraries(proj PUBLIC doctest::doctest default)
add_test(test test)
