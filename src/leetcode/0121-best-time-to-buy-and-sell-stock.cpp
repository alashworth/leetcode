#include <doctest/doctest.h>

#include <vector>

using namespace std;

int max_profit(vector<int> const & prices)
{
	int mbc = prices[0];
	int mp = 0;
	for (int i = 1; i < prices.size(); ++i) {
		mbc = min(prices[i], mbc);
		mp = max(prices[i] - mbc, mp);
	}
	return mp;
}

TEST_CASE("Example 1")
{
	vector<int> const prices { 7, 1, 5, 3, 6, 4 };

	REQUIRE_EQ(max_profit(prices), 5);
}