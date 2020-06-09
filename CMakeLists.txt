cmake_minimum_required(VERSION 2.8) # Проверка версии CMake.

project(MyGraphik)
set(SOURCE_EXE MyGraphik.cpp)
set(SOURCE_LIB TXlib.h)
add_library(TXlib.h STATIC ${SOURCE_LIB})
add_executable(MyGraphik ${SOURCE_EXE})
target_link_libraries(main TXlib.h)