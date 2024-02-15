# Preamble
cmake_minimum_required(VERSION 3.19)
project(cpp-puzzles)

# Project wide setup
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Externally provided content
include(FetchContent)
fetchcontent_declare(doctest
		GIT_REPOSITORY https://github.com/onqtam/doctest.git
		GIT_TAG 2.4.6
		GIT_SHALLOW
		)

fetchcontent_declare(sltbench
		GIT_REPOSITORY https://github.com/ivafanas/sltbench.git
		GIT_SHALLOW
		)

fetchcontent_makeavailable(sltbench doctest)

# Compile Options
if (GNU)
	add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wnon-virtual-dtor
			-Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion
			-Wsign-conversion -Wmisleading-indentation -Wduplicated-cond
			-Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast
			-Wdouble-promotion -Wformat=2)
elseif (CLANG)
	add_compile_options(-Weverything)
endif ()

# Main targets built by this project
add_subdirectory(src/leetcode)
add_subdirectory(src/euler)
add_subdirectory(src/misc)
add_subdirectory(bench)