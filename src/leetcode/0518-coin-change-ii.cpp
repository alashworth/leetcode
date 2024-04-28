#include <gtest/gtest.h>

#include <vector>

using namespace std;

int change(int amount, vector<int> & coins)
{
	vector<int> d(amount + 1, 0);

	d[0] = 1;
	for (auto k : coins) {
		for (int i = 0; i < static_cast<int>(d.size()) - k; ++i) {
			d[i + k] += d[i];
		}
	}

	return d.back();
}

TEST(LC0518, Example1)
{
	vector v { 1, 2, 5 };
	EXPECT_EQ(change(5, v), 4);
}

TEST(LC0518, Example2)
{
	vector v { 2 };
	EXPECT_EQ(change(3, v), 0);
}

TEST(LC0518, Example3)
{
	vector v { 10 };
	EXPECT_EQ(change(10, v), 1);
}

TEST(LC0518, Overflow)
{
	vector v { 7 };
	EXPECT_EQ(change(0, v), 1);
}