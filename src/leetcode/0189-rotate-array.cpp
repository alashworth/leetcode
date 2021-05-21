#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

using namespace std;

void rotvec(vector<int>& nums, int k)
{
	k %= nums.size();
	rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
}

TEST_CASE("Ex1")
{
	vector<int> v { 1, 2, 3, 4, 5, 6, 7 };
	int k = 3;
	rotvec(v, k);
	CHECK_EQ(vector<int> { 5, 6, 7, 1, 2, 3, 4 }, v);
}

TEST_CASE("k too big")
{
	vector<int> v { -1 };
	int k = 2;
	rotvec(v, k);
}