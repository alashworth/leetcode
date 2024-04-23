#include <gtest/gtest.h>

#include <vector>

using namespace std;

// # Longest Increasing Subsequence
// ## Recurrence
// Let d[i] be the length of the LIS that ends at i, including i.
int longest_increasing_subsequence_dp(vector<int> const & a)
{
	vector<int> d(a.size(), 1);
	int best = 1;
	for (int i = 1; i < d.size(); ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (a[i] > a[j])
				d[i] = max(d[i], d[j] + 1);
		}
		best = max(best, d[i]);
	}
	return best;
}

TEST(LC0300, Example1)
{
	vector<int> const input { 10, 9, 2, 5, 3, 7, 101, 18 };
	EXPECT_EQ(longest_increasing_subsequence_dp(input), 4);
}