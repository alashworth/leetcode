#include <gtest/gtest.h>

#include <vector>

using namespace std;

int mccs(vector<int> const & price)
{
	size_t N = price.size();
	vector<int> cost(N, 0);

	cost[0] = price[0];
	cost[1] = price[1];

	for (int i = 2; i < price.size(); ++i) {
		cost[i] = min(cost[i - 1], cost[i - 2]) + price[i];
	}

	return min(cost[N - 1], cost[N - 2]);
}

TEST(LC0746, Example1)
{
	vector<int> c { 10, 15, 20 };
	EXPECT_EQ(mccs(c), 15);
}

TEST(LC0746, Example2)
{
	vector<int> c { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	EXPECT_EQ(mccs(c), 6);
}