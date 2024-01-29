#include <doctest/doctest.h>

#include <vector>

using namespace std;

// Given an integer array A, return the length of the longest strictly
// increasing subsequence.

int lis(vector<int> const & a)
{
	size_t const n = a.size();
	vector<int> d(n, 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i]) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = d[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, d[i]);
	}
	return ans;
}

TEST_CASE("Example 1")
{
	vector<int> const input { 10, 9, 2, 5, 3, 7, 101, 18 };
	REQUIRE_EQ(lis(input), 4);
}