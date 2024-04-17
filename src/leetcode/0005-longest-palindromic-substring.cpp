#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

string longest_palindrome(string const & s)
{
	int longest_length = 0;
	int start_index = 0;
	int l;
	int r;
	for (int i = 0; i < s.size(); ++i) {
		// odd palindromes
		l = i;
		r = i;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r]) {
				int palindrome_length = r - l + 1;
				if (palindrome_length > longest_length) {
					start_index = l;
					longest_length = palindrome_length;
				}

			} else {
				break;
			}
			--l;
			++r;
		}

		// even palindromes
		l = i;
		r = i + 1;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r]) {
				int palindrome_length = r - l + 1;
				if (palindrome_length > longest_length) {
					start_index = l;
					longest_length = palindrome_length;
				}
			} else {
				break;
			}
			--l;
			++r;
		}
	}
	return s.substr(start_index, longest_length);
}

TEST(LC0005, Example1)
{
	string s = "babad";
	string r = longest_palindrome(s);
	EXPECT_EQ(r, "bab");
}

TEST(LC0005, Simple1)
{
	string s = "banana";
	string r = longest_palindrome(s);
	EXPECT_EQ("anana", r);
}

TEST(LC0005, Example2)
{
	string s = "cbbd";
	string r = longest_palindrome(s);
	EXPECT_EQ("bb", r);
}

TEST(LC0005, ShortPatterns)
{
	EXPECT_EQ("a", longest_palindrome("ac"));
	EXPECT_EQ("bb", longest_palindrome("abb"));
}

TEST(LC0005, AllIdentical) { EXPECT_EQ(longest_palindrome("aaaa"), "aaaa"); }