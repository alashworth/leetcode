#include <gtest/gtest.h>

#include <vector>

using namespace std;

bool canJump(vector<int> & nums)
{
	if (nums.size() == 1)
		return true;
	int fuel = 1;
	for (int i = 0; i < nums.size(); ++i) {
		fuel = max(fuel - 1, nums[i]);
		if (fuel <= 0 && i != nums.size() - 1)
			return false;
	}
	return true;
}

TEST(LC0055, Example1)
{
	vector v { 2, 3, 1, 1, 4 };
	EXPECT_TRUE(canJump(v));
}

TEST(LC0055, Example2)
{
	vector v { 3, 2, 1, 0, 4 };
	EXPECT_FALSE(canJump(v));
}

TEST(LC0055, Singleton)
{
	vector v { 0 };
	EXPECT_TRUE(canJump(v));
}

TEST(LC0055, TwoHundred)
{
	vector v { 2, 0, 0 };
	EXPECT_TRUE(canJump(v));
}