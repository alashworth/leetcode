#include <gtest/gtest.h>

#include <vector>

using namespace std;

int rob(vector<int> const & cash)
{
	auto N = cash.size();
	if (N == 1)
		return cash[0];

	vector<int> p(N, 0);

	p[0] = cash[0];
	p[1] = max(cash[0], cash[1]);

	for (int i = 2; i < N; ++i)
		p[i] = max(cash[i] + p[i - 2], p[i - 1]);

	return p[N - 1];
}

TEST(LC0198, Example1)
{
	vector<int> const nums { 1, 2, 3, 1 };
	EXPECT_EQ(rob(nums), 4);
}

TEST(LC0198, Example2)
{
	vector<int> const nums { 2, 7, 9, 3, 1 };
	EXPECT_EQ(rob(nums), 12);
}

TEST(LC0198, Example3)
{
	vector<int> const nums { 2, 1, 1, 2 };
	EXPECT_EQ(rob(nums), 4);
}

TEST(LC0198, ZeroCase)
{
	vector<int> const nums { 0 };
	EXPECT_EQ(rob(nums), 0);
}