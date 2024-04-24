#include <gtest/gtest.h>

#include <vector>

using namespace std;

static bool partitionable(vector<int> & n)
{
	int total = 0;
	for (auto v : n)
		total += v;

	if (total % 2 != 0)
		return false;

	int tgt = total / 2;
	vector<bool> d(tgt + 1, false);
	d[0] = true;
	for (int v : n) {
		for (int i = tgt; i >= 0; --i) {
			if (i + v > d.size())
				continue;
			if (d[i])
				d[i + v] = true;
		}
	}

	return d.back();
}

TEST(LC0416, Example1)
{
	vector<int> n { 1, 5, 11, 5 };
	EXPECT_TRUE(partitionable(n));
}

TEST(LC0416, Failing1)
{
	vector<int> n { 14, 9, 8, 4, 3, 2 };
	EXPECT_TRUE(partitionable(n));
}

TEST(LC0416, Failing2)
{
	vector<int> n { 1, 2, 5 };
	EXPECT_FALSE(partitionable(n));
}