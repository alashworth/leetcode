#include <gtest/gtest.h>

#include <vector>

using namespace std;

static int max_profit(vector<int> & prices)
{
	vector<int> sell(prices.size(), 0);
	vector<int> buy_or_hold(prices.size(), 0);
	vector<int> pass(prices.size(), 0);

	// We need the pass state because we need to remember the total profit
	// from before the sell->buy cooldown.
	buy_or_hold[0] = -prices[0];
	for (int i = 1; i < prices.size(); ++i) {
		pass[i] = sell[i - 1];
		sell[i] = max(sell[i - 1], buy_or_hold[i - 1] + prices[i]);
		buy_or_hold[i] = max(buy_or_hold[i - 1], pass[i - 1] - prices[i]);
	}
	return sell[prices.size() - 1];
}

TEST(LC0309, Example1)
{
	vector<int> v { 1, 2, 3, 0, 2 };
	int p = 3;
	EXPECT_EQ(max_profit(v), p);
}

TEST(LC0309, Example2)
{
	vector<int> v { 1 };
	int p = 0;
	EXPECT_EQ(max_profit(v), p);
}
