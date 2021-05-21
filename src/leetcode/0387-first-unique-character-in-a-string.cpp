#include <doctest/doctest.h>

#include <algorithm>
#include <array>
#include <string>

using namespace std;

// Given a string, find the first non-repeating character in it and return it's
// index. If it doesn't exist, return -1.

// Note: You may assume the string contain only lowercase letters.

int first_unique(string const& s)
{
	// Initially, the array is filled with INT_MAX. Each position corresponds to
	// an ASCII lowercase letter.  When a character is seen, the array is
	// updated to reflect the index where it was seen. If a character is
	// subsequently seen, the value is updated to INT_MAX - 1. Then finding the
	// first non-repeating character consists of finding the minimum value in
	// the array.
	array<int, 26> seen; // NOLINT
	seen.fill(INT_MAX);

	for (size_t i = 0; i < s.length(); i++) {
		auto d = static_cast<size_t>(s[i] - 97);
		auto v = static_cast<size_t>(seen[d]);
		if (v == INT_MAX) {
			seen[d] = static_cast<int>(i);
		} else if (v == INT_MAX - 1) {
			continue;
		} else {
			seen[d] = INT_MAX - 1;
		}
	}

	auto result = min_element(seen.begin(), seen.end());
	if (*result < INT_MAX - 1) {
		return *result;
	} else {
		return -1;
	}
}

TEST_CASE("Example 1") { CHECK(first_unique("leetcode") == 0); }

TEST_CASE("Example 2") { CHECK(first_unique("loveleetcode") == 2); }