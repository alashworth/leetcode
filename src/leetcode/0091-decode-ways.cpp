#include <gtest/gtest.h>

#include <string>

using namespace std;

static int ndecode(string const & s)
{
	vector<int> cnt(s.size(), 0);

	if (s[0] == '0')
		return 0;

	if (s.size() == 1)
		return 1;

	cnt[0] = 1;
	cnt[1] = s[1] != '0' ? 1 : 0;
	cnt[1] += (s[0] == '1' || (s[0] == '2' && s[1] < '7')) ? 1 : 0;
	for (int i = 2; i < s.size(); ++i) {
		if (s[i] != '0')
			cnt[i] = cnt[i - 1];

		if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
			cnt[i] += cnt[i - 2];
	}

	return cnt.back();
}

TEST(LC0091, Example1) { EXPECT_EQ(ndecode("12"), 2); }

TEST(LC0091, Example2) { EXPECT_EQ(ndecode("226"), 3); }

TEST(LC0091, Example3) { EXPECT_EQ(ndecode("06"), 0); }

TEST(LC0091, UserDefined1) { EXPECT_EQ(ndecode("1110"), 2); }

TEST(LC0091, UserDefined2) { EXPECT_EQ(ndecode("60"), 0); }

TEST(LC0091, UserDefined3) { EXPECT_EQ(ndecode("111"), 3); }

TEST(LC0091, UserDefined4) { EXPECT_EQ(ndecode("10"), 1); }

TEST(LC0091, UserDefined5) { EXPECT_EQ(ndecode("27"), 1); }

TEST(LC0091, UserDefined6) { EXPECT_EQ(ndecode("26"), 2); }