add_executable(misc
        dpv61-contiguous-subsequence.cpp
        dpv63-yuckdonalds.cpp
        dpv33-topological-order.cpp
)

target_link_libraries(misc PRIVATE doctest_with_main spdlog)