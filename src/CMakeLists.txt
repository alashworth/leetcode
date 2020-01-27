add_executable(leetcode
		0001-two-sum.cpp
		0002-add-two-numbers.cpp
		0003-longest-substring-without-repeating-characters.cpp
		0004-median-of-two-sorted-arrays.cpp
		0072-edit-distance.cpp
		0125-valid-palindrome.cpp
		0242-valid-anagram.cpp
		0387-first-unique-character-in-a-string.cpp
		1108-defanging-an-ip-address.cpp
		)

target_link_libraries(leetcode PRIVATE doctest_with_main)
target_compile_definitions(leetcode PRIVATE DOCTEST_CONFIG_SUPER_FAST_ASSERTS)