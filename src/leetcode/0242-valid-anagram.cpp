#include <doctest/doctest.h>

#include <algorithm>
#include <array>
#include <string>

using namespace std;

// Given two strings s and t , write a function to determine if t is an anagram
// of s.
//
// Note: You may assume the string contains only lowercase alphabets.
bool is_anagram(const string& s1, string const& s2)
{
	array<int, 26> hist {};

	for (auto const c : s1) {
		++hist[static_cast<size_t>(c - 'a')];
	}

	for (auto const c : s2) {
		--hist[static_cast<size_t>(c - 'a')];
	}

	if (!ranges::all_of(hist, [](auto const & i) { return i == 0; })) {
		return false;
	}
	return true;
}

TEST_CASE("Example 1") { CHECK(is_anagram("anagram", "nagaram")); }

TEST_CASE("Example 2") { CHECK(!is_anagram("rat", "car")); }