#include <gtest/gtest.h>

using namespace std;

static int ftsw1(vector<int> const & n, int g)
{
	int sum = 0;
	for (auto v : n)
		sum += v;

	if (g < -sum || g > sum)
		return 0;

	vector<vector<int>> dp(n.size() + 1, vector(2 * sum + 1, 0));
	dp[0][sum] = 1;
	int i = 0;
	for (int v : n) {
		++i;
		for (int j = 0; j <= 2 * sum - v; ++j)
			dp[i][j + v] += dp[i - 1][j];
		for (int j = v; j < dp[i].size(); ++j)
			dp[i][j - v] += dp[i - 1][j];
	}
	int result = dp.back()[sum + g];
	return result;
}

TEST(LC0494, Example1)
{
	vector v { 1, 1, 1, 1, 1 };
	int t = 3;
	EXPECT_EQ(ftsw1(v, t), 5);
}