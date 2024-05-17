#include <gtest/gtest.h>

int lengthOfLongestSubstring(char const * s)
{
	int N = strlen(s);
	if (!N)
		return 0;

	unsigned short seen[256];
	memset(seen, 0xFF, sizeof seen);
	unsigned short previous = 1, current, max_seen = 1;
	seen[s[0]] = 0;
	for (int i = 1; i < N; ++i) {
		char c = s[i];
		if (seen[c] == USHRT_MAX) {
			seen[c] = i;
			current = previous + 1;
		} else {
			current = i - seen[c];
			if (previous < current) {
				current = previous + 1;
			}
			seen[c] = i;
		}
		if (current > max_seen)
			max_seen = current;
		previous = current;
	}
	return max_seen;
}

TEST(LC0003, Example3)
{
	char const * s = "pwwkew";
	EXPECT_EQ(lengthOfLongestSubstring(s), 3);
}

TEST(LC0003, TC139)
{
	char const * s = "abba";
	EXPECT_EQ(lengthOfLongestSubstring(s), 2);
}