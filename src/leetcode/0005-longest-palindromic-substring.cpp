#include <doctest/doctest.h>

#include <string>
#include <vector>

using namespace std;

// there is a specialized algorithm (Mannacher's) but realistically
// you won't remember it during a timed interview, so what follows is the
// standard dynamic programming solution
// runtime complexity O(n^2), space complexity O(n^2)

// We have a 2d table. each row represents whether the substring ending at j
// and of length i is a palindrome.
// t[0, j] = true, all length-1 strings are trivially palindromes
// t[1, j>0] = true, all length-2 strings are trivially palindromes
// t[i,j] = t[i-2,j-1] && (s[j]==s[j-i])
// the maximal palindrome is given by the column with the max value
string longest_palindrome(string const & s)
{
	auto const N = s.size();
	if (N == 1)
		return s;
	if (N == 2) {
		if (s[0] == s[1])
			return s;
		return { s[0] };
	}
	vector t(N, vector(N, false));

	int m = 0;
	int n = 0;
	for (int i = 0; i < N; ++i)
		t[0][i] = true;
	for (int i = 1; i < N; ++i)
		if (s[i] == s[i - 1]) {
			t[1][i] = true;
			n = i;
			m = 1;
		}
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; ++j) {
			if (s[j] == s[j - i]) {
				if (t[i - 2][j - 1]) {
					t[i][j] = true;
					m = i;
					n = j;
				}
			}
		}
	}
	return s.substr(n - m, m + 1);
}

TEST_CASE("Example 1")
{
	string s = "babad";
	string r = longest_palindrome(s);
	REQUIRE_EQ("aba", r);
}

TEST_CASE("Simple Case")
{
	string s = "banana";
	string r = longest_palindrome(s);
	REQUIRE_EQ("anana", r);
}

TEST_CASE("Example 2")
{
	string s = "cbbd";
	string r = longest_palindrome(s);
	REQUIRE_EQ("bb", r);
}

TEST_CASE("Longest Palindrome - Short Test Pattern")
{
	REQUIRE_EQ("a", longest_palindrome("ac"));
	REQUIRE_EQ("bb", longest_palindrome("abb"));
}