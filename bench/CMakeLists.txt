add_definitions(-DDOCTEST_CONFIG_DISABLE)

add_executable(0072-bench 0072-edit-distance.cpp)
target_link_libraries(0072-bench doctest sltbench)

target_compile_definitions(0072-bench PRIVATE DOCTEST_CONFIG_DISABLE)