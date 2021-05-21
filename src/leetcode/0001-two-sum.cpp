#include <doctest/doctest.h>

#include <unordered_map>
#include <vector>

using namespace std;

// Given an array of integers, return indices of the two numbers such that they
// add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may
// not use the same element twice.
vector<int> two_sum(vector<int> const& nums, int target)
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

TEST_CASE("1: solution passes example")
{
	vector<int> vec { 2, 7, 11, 15 };
	int target = 9;
	REQUIRE_EQ(two_sum(vec, target), vector<int> { 0, 1 });
}