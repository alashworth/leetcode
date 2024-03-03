#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

// see related 0041 & 0268

vector<int> fdn(vector<int> & n)
{
	// modified cycle sort
	size_t N = n.size();
	for (int i = 1; i <= N; i++) {
		while (i != n[i - 1]) {
			if (n[i - 1] > N || n[n[i - 1] - 1] == n[i - 1])
				break;
			swap(n[n[i - 1] - 1], n[i - 1]);
		}
	}

	vector<int> r {};
	r.reserve(8);
	for (int i = 0; i < N; i++) {
		int j = i + 1;
		if (j != n[i]) {
			r.push_back(j);
		}
	}
	return r;
}

TEST_SUITE("0448-find-disappeared-numbers")
{
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
}
