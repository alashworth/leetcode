#include <gtest/gtest.h>

#include <cctype>

static bool is_palindrome(const char * s)
{
	int l = 0;
	int r = 0;
	while (*(s + r + 1) != '\0')
		++r;

	/* convert or remove character */
	while (l < r) {
		char a = s[l];
		char b = s[r];

		// happy case, no preprocessing needed
		if (a == b) {
			l++, r--;
			continue;
		}

		bool notalnum = false;
		if (isalnum(a) == 0) {
			l++;
			notalnum = true;
		}
		if (isalnum(b) == 0) {
			r--;
			notalnum = true;
		}
		if (notalnum)
			continue;

		a = tolower(a);
		b = tolower(b);

		if (a == b)
			l++, r--;
		else
			return false;
	}

	return true;
}

TEST(LC0125, Example1)
{
	auto s = "A man, a plan, a canal: Panama";
	EXPECT_TRUE(is_palindrome(s));
}