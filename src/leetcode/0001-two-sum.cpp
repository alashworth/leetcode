#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int> const & nums, int target)
{
	unordered_map<int, int> seen;
	for (int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];
		if (seen.count(complement)) {
			return { seen[complement], i };
		} else {
			seen.insert({ nums[i], i });
		}
	}
	return { 0, 0 };
}

TEST(LC0001, Example1)
{
	vector<int> vec { 2, 7, 11, 15 };
	int target = 9;
	EXPECT_EQ(two_sum(vec, target), (vector<int> { 0, 1 }));
}