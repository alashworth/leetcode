#include <doctest/doctest.h>

#include <string>

using namespace std;

// Given two strings s and t, return true if s is a subsequence of t, or false
// otherwise.

bool is_subsequence(string s, string t)
{
	int j = 0;
	for (int i = 0; i < t.length(); ++i) {
		if (t[i] == s[j]) {
			++j;
		}
	}
	if (j == s.length()) {
		return true;
	}
	return false;
}
