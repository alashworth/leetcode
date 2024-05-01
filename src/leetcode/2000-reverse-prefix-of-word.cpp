#include <cstring>
#include <gtest/gtest.h>

char * reversePrefix(char * word, char ch)
{
	// find the index of the first occurrence of ch
	unsigned char idx = 0;
	while (word[idx] != ch) {
		if (word[idx] == '\0')
			return word;
		++idx;
	}

	// reverse the subsequence
	unsigned char l = 0;
	unsigned char r = idx;
	while (l < r) {
		char tmp = word[r];
		word[r] = word[l];
		word[l] = tmp;
		l += 1;
		r -= 1;
	}

	return word;
}

TEST(LC2000, Example1)
{
	char w[] { "abcdefd" };
	char d { 'd' };
	char expected[] { "dcbaefd" };
	EXPECT_FALSE(strcmp(reversePrefix(w, d), expected));
}