add_definitions(-DDOCTEST_CONFIG_DISABLE)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(0072-bench 0072-edit-distance.cpp)
target_link_libraries(0072-bench doctest sltbench)
