add_executable(leetcode
        0442-find-all-duplicates.cpp
        0713-subarray_product_lt_k.cpp
        0041-first-missing-positive.cpp
        2958-len-longest-sub-le-k.cpp
        2962-count-subarrays-max-k.cpp
        0056-subarray-sum-eq-k.cpp
)

target_link_libraries(leetcode PUBLIC
        GTest::gtest_main
)
