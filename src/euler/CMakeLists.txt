add_executable(euler
		0002-even-fibonacci-numbers.cpp
		0003-largest-prime-factor.cpp
		0004-largest-palindrome-product.cpp
		0005-smallest-multiple.cpp
		0006-sum-square-difference.cpp
		0007-10001st-prime.cpp
		0008-largest-product-in-a-series.cpp
		0009-special-pythagorean-triplet.cpp
		0010-summation-of-primes.cpp
		0011-largest-product-in-grid.cpp
		)

target_link_libraries(euler PRIVATE doctest_with_main)