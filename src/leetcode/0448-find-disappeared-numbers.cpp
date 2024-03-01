#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

// see related 0041 & 0268

vector<int> fdn(vector<int> & nums)
{
	for (int i = 0; i < nums.size(); ++i) {
		while (i != nums[i]) { }
	}
}

TEST_CASE("Example 1")
{
	vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	REQUIRE(ranges::equal(fdn(nums), vector<int> { 5, 6 }));
}

TEST_CASE("Example 2")
{
	vector<int> nums = { 1, 1 };
	REQUIRE(ranges::equal(fdn(nums), vector<int> { 2 }));
}
