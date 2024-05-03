#include <gtest/gtest.h>

#include <algorithm>
#include <string>

using namespace std;

bool is_anagram(const string & s1, string const & s2)
{
	int t[26] = { 0 };
	for (char const c : s1)
		++t[c - 97];
	for (char const c : s2)
		--t[c - 97];
	for (int const v : t)
		if (v != 0)
			return false;
	return true;
}

TEST(LC0242, Example1)
{
	string s1 { "anagram" };
	string s2 { "nagaram" };
	EXPECT_TRUE(is_anagram(s1, s2));
}

TEST(LC0242, Example2)
{
	string s1 { "rat" };
	string s2 { "car" };
	EXPECT_FALSE(is_anagram(s1, s2));
}