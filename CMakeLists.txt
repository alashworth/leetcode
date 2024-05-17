# Preamble
cmake_minimum_required(VERSION 3.22)
project(cpp-puzzles)

# Project wide setup
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

find_package(GTest REQUIRED)
find_package(benchmark REQUIRED)

# Compile Options
if (GNU)
    add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wnon-virtual-dtor
            -Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion
            -Wsign-conversion -Wmisleading-indentation -Wduplicated-cond
            -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast
            -Wdouble-promotion -Wformat=2 -Wformat-signedness -Wpadded)
elseif (CLANG)
    add_compile_options(-Weverything)
endif ()

# Main targets built by this project
add_subdirectory(src/leetcode)
add_subdirectory(src/euler)
add_subdirectory(src/misc)
add_subdirectory(bench)