#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> three_sum(vector<int> & nums)
{
	vector<vector<int>> result;
	ranges::sort(nums);
	for (int i = 0; i < nums.size(); ++i) {
		int a = nums[i];
		if (i > 0 && a == nums[i - 1])
			continue;
		int l = i + 1, r = nums.size() - 1;
		while (l < r) {
			int sum = a + nums[l] + nums[r];
			if (sum > 0)
				r -= 1;
			else if (sum < 0)
				l += 1;
			else {
				result.push_back({ a, nums[l], nums[r] });
				l++;
				while (nums[l] == nums[l - 1] && l < r)
					l++;
			}
		}
	}
	return result;
}

TEST(LC0015, Example1)
{
	vector nums { -1, 0, 1, 2, -1, -4 };
	auto rv = three_sum(nums);
	vector<vector<int>> expected { { -1, 0, 1 }, { -1, -1, 2 } };
	EXPECT_EQ(three_sum(nums), expected);
}