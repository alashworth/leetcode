#include <gtest/gtest.h>

#include <string>

using namespace std;

static int count_substrings(const string & s)
{
	int cnt = 0;

	for (int i = 0; i < s.size(); ++i) {
		// odd palindromes
		int l = i;
		int r = i;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r])
				++cnt;
			else
				break;
			--l;
			++r;
		}

		// even palindromes
		l = i;
		r = i + 1;
		while (l >= 0 && r < s.size()) {
			if (s[l] == s[r])
				++cnt;
			else
				break;
			--l;
			++r;
		}
	}

	return cnt;
}

TEST(LC0647, Example1)
{
	auto s { "abc" };
	EXPECT_EQ(count_substrings(s), 3);
}

TEST(LC0647, Example2)
{
	auto s { "aaa" };
	EXPECT_EQ(count_substrings(s), 6);
}