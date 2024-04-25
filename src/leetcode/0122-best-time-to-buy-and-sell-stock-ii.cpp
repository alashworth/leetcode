#include <gtest/gtest.h>

#include <numeric>
#include <vector>

using namespace std;

static int max_profit(vector<int> & prices)
{
	int profit = 0;
	for (int i = 1; i < prices.size(); ++i) {
		int p = prices[i] - prices[i - 1];
		if (p > 0)
			profit += p;
	}
	return profit;
}

TEST(LC0122, Example1)
{
	vector<int> v { 7, 1, 5, 3, 6, 4 };
	int p = 7;
	EXPECT_EQ(max_profit(v), p);
}

TEST(LC0122, Example2)
{
	vector<int> v { 1, 2, 3, 4, 5 };
	int p = 4;
	EXPECT_EQ(max_profit(v), p);
}

TEST(LC0122, Example3)
{
	vector<int> v { 7, 6, 4, 3, 1 };
	int p = 0;
	EXPECT_EQ(max_profit(v), p);
}