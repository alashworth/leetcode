add_executable(leetcode
        0402-remove-k-digits.cpp
        0442-find-all-duplicates.cpp
        0713-subarray_product_lt_k.cpp
        0041-first-missing-positive.cpp
        2958-len-longest-sub-le-k.cpp
        2962-count-subarrays-max-k.cpp
        0056-subarray-sum-eq-k.cpp
        0992-subarrays-with-k-distinct.cpp
        1700-number-of-students-unable-to-eat-lunch.cpp
        0746-min-cost-climbing-stairs.cpp
        0198-house-robber.cpp
        0213-house-robber-ii.cpp
        0647-palindromic-substrings.cpp
        0005-longest-palindromic-substring.cpp
        0091-decode-ways.cpp
)

target_link_libraries(leetcode PUBLIC
        GTest::gtest_main
)
