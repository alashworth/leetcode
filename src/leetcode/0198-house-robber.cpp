#include <doctest/doctest.h>

#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

int rob(vector<int> const & nums)
{
	if (nums.size() == 1)
		return nums[0];
	if (nums.size() == 2)
		return max(nums[0], nums[1]);

	vector<int> d(nums.size());
	d[0] = nums[0];
	d[1] = max(nums[0], nums[1]);
	for (int i = 2; i < nums.size(); ++i) {
		d[i] = max(d[i - 1], nums[i] + d[i - 2]);
	}
	return d.back();
}

TEST_CASE("Example 1")
{
	vector<int> const nums { 1, 2, 3, 1 };
	REQUIRE_EQ(rob(nums), 4);
}

TEST_CASE("Example 2")
{
	vector<int> const nums { 2, 7, 9, 3, 1 };
	REQUIRE_EQ(rob(nums), 12);
}

TEST_CASE("Valuable Ends")
{
	vector<int> const nums { 2, 1, 1, 2 };
	REQUIRE_EQ(rob(nums), 4);
}