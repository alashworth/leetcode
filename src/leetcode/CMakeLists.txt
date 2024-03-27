add_executable(leetcode
        0442-find-all-duplicates.cpp
        0713-subarray_product_lt_k.cpp
        0041-first-missing-positive.cpp
)

target_link_libraries(leetcode PUBLIC
        GTest::gtest_main
)
