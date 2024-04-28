#include <gtest/gtest.h>

#include <vector>

using namespace std;

static int search(vector<int> & nums, int target)
{
	int l = 0;
	int r = nums.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (nums[mid] < target)
			l = mid + 1;
		else if (nums[mid] > target)
			r = mid - 1;
		else
			return mid;
	}
	return -1;
}

TEST(LC0704, Examples)
{
	vector v { -1, 0, 3, 5, 9, 12 };
	EXPECT_EQ(search(v, 9), 4);
	EXPECT_EQ(search(v, 2), -1);
}