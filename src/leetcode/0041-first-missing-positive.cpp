#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

// hard difficulty problem

// requires knowing cycle sort, a quite esoteric sorting algorithm that
// works in place and in linear time, but only with very hard to satisfy prereqs
// # of distinct values < length of input
// you know how many of each value are present

// for this problem, we have to find the smallest positive integer not in the
// array. this integer must lie in the range [1..N], where N is the length of
// the input array.

int fmp(vector<int> & nums)
{
	int x = numeric_limits<int>::max();

	for (auto n : nums) {
		if (n >= 0) {
			x = min(n, x);
		}
	}

	return -1;
}

TEST_CASE("Example 1")
{
	vector<int> nums = { 1, 2, 0 };
	REQUIRE_EQ(fmp(nums), 3);
}

TEST_CASE("Example 2")
{
	vector<int> nums = { 3, 4, -1, 1 };
	REQUIRE_EQ(fmp(nums), 2);
}

TEST_CASE("Example 1")
{
	vector<int> nums = { 7, 8, 9, 11, 12 };
	REQUIRE_EQ(fmp(nums), 1);
}