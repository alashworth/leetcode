#include <gtest/gtest.h>

#include <algorithm>

using namespace std;

static int max_product(vector<int> & n)
{
	int pos = n[0];
	int neg = n[0];
	int best = n[0];
	for (int i = 1; i < n.size(); ++i) {
		int old_pos = pos;
		int old_neg = neg;

		pos = max(n[i] * old_pos, n[i] * old_neg);
		pos = max(pos, n[i]);

		neg = min(n[i] * old_pos, n[i] * old_neg);
		neg = min(neg, n[i]);

		best = max(best, pos);
	}
	return best;
}

TEST(LC0152, Example1)
{
	vector<int> n { 2, 3, -2, 4 };
	EXPECT_EQ(max_product(n), 6);
}

TEST(LC0152, Example2)
{
	vector<int> n { -2, 0, -1 };
	EXPECT_EQ(max_product(n), 0);
}

TEST(LC0152, Fail1)
{
	vector<int> n { 3, -1, 4 };
	EXPECT_EQ(max_product(n), 4);
}

TEST(LC0152, Fail2)
{
	vector<int> n { 2, -5, -2, -4, 3 };
	EXPECT_EQ(max_product(n), 24);
}