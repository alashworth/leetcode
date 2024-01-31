add_executable(leetcode
		0001-two-sum.cpp
		0002-add-two-numbers.cpp
		0003-longest-substring-without-repeating-characters.cpp
		0004-median-of-two-sorted-arrays.cpp
		0019-remove-nth-node-from-end-of-list.cpp
		0048-rotate-image.cpp
		0072-edit-distance.cpp
		0083-remove-duplicates-from-sorted-list.cpp
		0125-valid-palindrome.cpp
		0189-rotate-array.cpp
		0215-kth-largest-element-in-an-array.cpp
		0242-valid-anagram.cpp
		0387-first-unique-character-in-a-string.cpp
		1108-defanging-an-ip-address.cpp
		1114-print-in-order.cpp
		0300-longest-increasing-subsequence.cpp
        0322-coin-change.cpp
        0338-counting-bits.cpp)

target_link_libraries(leetcode PRIVATE doctest_with_main)