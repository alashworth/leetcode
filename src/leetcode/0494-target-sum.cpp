#include <gtest/gtest.h>

#include <numeric>

using namespace std;

static int find_target_sum_ways(vector<int> & nums, int target)
{
	int N = nums.size();
	int M = accumulate(nums.begin(), nums.end(), 0) * 2 + 2;

	return 0;
}

TEST(LC0494, Example1)
{
	vector v { 1, 1, 1, 1, 1 };
	int t = 3;
	EXPECT_EQ(find_target_sum_ways(v, t), 5);
}