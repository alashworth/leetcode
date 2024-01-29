#include <doctest/doctest.h>
#include <limits>
#include <vector>

using namespace std;

// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If
// that amount of money cannot be made up by any combination of the coins,
// return -1. You may assume that you have an infinite number of each kind of
// coin.

int make_change(vector<int> const & coins, int const amount)
{
	vector<int> d(amount + 1, numeric_limits<int>::max());
	d[0] = 0;
	for (int i = 0; i < amount; ++i) {
		for (int const v : coins) {
			if (v > amount || i + v > amount)
				continue;
			if (d[i] < d[i + v])
				d[i + v] = d[i] + 1;
		}
	}

	return d[amount] == numeric_limits<int>::max() ? -1 : d[amount];
}

TEST_CASE("Example 1")
{
	vector<int> const coins { 1, 2, 5 };
	int constexpr amount = 11;

	REQUIRE_EQ(make_change(coins, amount), 3);
}

TEST_CASE("Numeric Overflow")
{
	vector<int> const coins {2147483647};
	int constexpr amount = 2;

	REQUIRE_EQ(make_change(coins, amount), -1);
}

TEST_CASE("Huge Coins 2")
{
	vector<int> const coins {474,83,404,3};
	int constexpr amount = 264;

	REQUIRE_EQ(make_change(coins, amount), 8);
}