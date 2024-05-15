add_executable(leetcode
        0001-two-sum.cpp
        0005-longest-palindromic-substring.cpp
        0041-first-missing-positive.cpp
        0062-unique-paths.cpp
        0074-search-a-2d-matrix.cpp
        0091-decode-ways.cpp
        0121-best-time-to-buy-and-sell-stock.cpp
        0122-best-time-to-buy-and-sell-stock-ii.cpp
        0139-word-break.cpp
        0152-maximum-product-subarray.cpp
        0165-compare-version-numbers.cpp
        0198-house-robber.cpp
        0213-house-robber-ii.cpp
        0217-contains-duplicate.cpp
        0242-valid-anagram.cpp
        0300-longest-increasing-subsequence.cpp
        0309-best-time-to-buy-and-sell-stock-with-cooldown.cpp
        0322-coin-change.cpp
        0402-remove-k-digits.cpp
        0416-partition-equal-subset-sum.cpp
        0442-find-all-duplicates.cpp
        0494-target-sum.cpp
        0518-coin-change-ii.cpp
        0560-subarray-sum-eq-k.cpp
        0647-palindromic-substrings.cpp
        0704-binary-search.cpp
        0713-subarray_product_lt_k.cpp
        0746-min-cost-climbing-stairs.cpp
        0992-subarrays-with-k-distinct.cpp
        1143-longest-common-subsequence.cpp
        1700-number-of-students-unable-to-eat-lunch.cpp
        2000-reverse-prefix-of-word.cpp
        2441-largest-positive-integer-that-exists-with-its-negative.cpp
        2958-len-longest-sub-le-k.cpp
        2962-count-subarrays-max-k.cpp
        0881-boats-to-save-people.cpp
        0125-valid-palindrome.cpp
        0237-delete-node-in-a-linked-list.cpp
        0049-group-anagrams.cpp
        2487-remove-nodes-from-linked-list.cpp
        2816-double-a-number-represented-as-a-linked-list.cpp
        0506-relative-ranks.cpp
        3075-maximize-happiness-of-selected-children.cpp
        0786-kth-smallest-prime-fraction.cpp
        0857-minimum-cost-to-hire-k-workers.cpp
        0146-lru-cache.cpp
        0861-score-after-flipping-matrix.cpp
        0020-valid-parentheses.cpp
)

target_link_libraries(leetcode PUBLIC
        GTest::gtest_main
)

target_compile_options(leetcode PUBLIC -fsanitize=address)
target_link_options(leetcode PUBLIC -fsanitize=address)
