# Preamble
cmake_minimum_required(VERSION 3.14)
project(leetcode)

# Project wide setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

# Externally provided content
include(FetchContent)
include(ExternalProject)

fetchcontent_declare(doctest
		GIT_REPOSITORY https://github.com/onqtam/doctest.git
		GIT_TAG 2.3.6
		GIT_SHALLOW)

fetchcontent_declare(sltbench
		GIT_REPOSITORY https://github.com/alashworth/sltbench.git
		GIT_TAG master
		GIT_SHALLOW)

fetchcontent_makeavailable(doctest sltbench)

# Compile Options
if (GNU)
	add_compile_options(-Wall -Wextra -pedantic -Wshadow -Wnon-virtual-dtor
			-Wold-style-cast -Wcast-align -Wunused -Woverloaded-virtual -Wconversion
			-Wsign-conversion -Wmisleading-indentation -Wduplicated-cond
			-Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast
			-Wdouble-promotion -Wformat=2 -Weffc++)
elseif (CLANG)
	add_compile_options(-Weverything -Wno-C++-98-compat -Wno-c++-compat)
endif ()

add_compile_options($<$<CONFIG:DEBUG>:-Werror>)

# Main targets built by this project
add_subdirectory(src)
add_subdirectory(bench)