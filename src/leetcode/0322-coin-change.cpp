#include <gtest/gtest.h>

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int uccp(vector<int> & coins, int amt)
{
	vector<int> a(amt + 1, numeric_limits<int>::max());

	a[0] = 0;
	sort(coins.begin(), coins.end());
	for (int i = 1; i <= amt; ++i) {
		for (int c : coins) {
			if (i < c)
				break;
			if (a[i - c] != numeric_limits<int>::max())
				a[i] = min(a[i], a[i - c] + 1);
		}
	}
	return a[amt] == numeric_limits<int>::max() ? -1 : a[amt];
}

TEST(LC0322, Example1)
{
	vector<int> coins { 1, 2, 5 };
	int amount = 11;

	EXPECT_EQ(uccp(coins, amount), 3);
}

TEST(LC0322, NumericOverflow)
{
	vector<int> coins { 2147483647 };
	int amount = 2;

	EXPECT_EQ(uccp(coins, amount), -1);
}

TEST(LC0322, HugeCoins2)
{
	vector<int> coins { 474, 83, 404, 3 };
	int amount = 264;

	EXPECT_EQ(uccp(coins, amount), 8);
}

TEST(LC0322, India)
{
	vector<int> coins { 5, 10, 20, 25 };
	int amount = 40;

	EXPECT_EQ(uccp(coins, amount), 2);
}

TEST(LC0322, NoNickels)
{
	vector<int> coins { 1, 10, 25 };
	int amount = 40;

	EXPECT_EQ(uccp(coins, amount), 4);
}