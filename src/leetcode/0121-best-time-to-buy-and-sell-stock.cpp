#include <gtest/gtest.h>

#include <vector>

using namespace std;

static int max_profit(vector<int> const & prices)
{
	int min_price = numeric_limits<int>::max();
	int max_profit = numeric_limits<int>::min();
	for (auto p : prices) {
		min_price = min(min_price, p);
		int profit = p - min_price;
		max_profit = max(max_profit, profit);
	}
	return max_profit;
}

TEST(LC0121, Example1)
{
	vector<int> const prices { 7, 1, 5, 3, 6, 4 };

	EXPECT_EQ(max_profit(prices), 5);
}