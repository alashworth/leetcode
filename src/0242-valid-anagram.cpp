#include <doctest/doctest.h>

#include <array>
#include <string>

using namespace std;

// Given two strings s and t , write a function to determine if t is an anagram
// of s.
//
// Note: You may assume the string contains only lowercase alphabets.
bool is_anagram(string s1, string s2) {
  array<int, 26> hist{};

  for (auto c : s1) {
    ++hist[static_cast<size_t>(c - 'a')];
  }

  for (auto c : s2) {
    --hist[static_cast<size_t>(c - 'a')];
  }

  for (auto i : hist) {
    if (i != 0) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Example 1") { CHECK(is_anagram("anagram", "nagaram")); }

TEST_CASE("Example 2") { CHECK(!is_anagram("rat", "car")); }