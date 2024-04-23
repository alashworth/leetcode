#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

// # Dynamic Programming
// ## Recurrence.
// Suppose we have a boolean array bp indexed starting at 0
// bp[i]: a breakpoint exists at i, i.e. a new word could start there
// therefore in leetcode, bp[0], bp[4]
bool word_break(string & s, vector<string> & dict)
{
	vector<bool> bp(s.size() + 1, false);

	bp[0] = true;
	for (int i = 1; i < bp.size(); ++i) {
		for (string & d : dict) {
			if (i < d.size() || !bp[i - d.size()])
				continue;
			auto v = s.substr(i - d.size(), d.size());
			if (d == v)
				bp[i] = true;
		}
	}

	return bp.back();
}

TEST(LC0139, Example1)
{
	string s { "leetcode" };
	vector<string> d { "leet", "code" };
	EXPECT_EQ(word_break(s, d), true);
}

TEST(LC0139, Example2)
{
	string s { "applepenapple" };
	vector<string> d { "apple", "pen" };
	EXPECT_EQ(word_break(s, d), true);
}

TEST(LC0139, Example3)
{
	string s { "catsandog" };
	vector<string> d { "cats", "dog", "sand", "and", "cat" };
	EXPECT_EQ(word_break(s, d), false);
}