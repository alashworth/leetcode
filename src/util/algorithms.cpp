#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

namespace {
int binary_search(vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size() - 1;
	while (l <= r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] < v)
			l = m + 1;
		else if (n[m] > v)
			r = m - 1;
		else
			return m;
	}
	return -1;
}

int binary_search_left(vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size();
	while (l < r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] < v)
			l = m + 1;
		else
			r = m;
	}
	return l;
}

int binary_search_right(vector<int> const & n, int v)
{
	int l = 0;
	int r = n.size();
	while (l < r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		if (n[m] > v)
			r = m;
		else
			l = m + 1;
	}
	return r - 1;
}

int knapsack_01(vector<int> const & values, vector<int> const & weights,
	int const max_weight)
{
	assert(values.size() == weights.size());
	vector<vector<int>> dp(values.size() + 1, vector<int>(max_weight + 1, 0));
	auto & v = values;
	auto & w = weights;
	int N = values.size();
	auto & W = max_weight;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (w[i] > j) // item too big to fit
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
}
} // namespace
