#include <algorithm>
#include <cstdint>
#include <iostream>

using namespace std;

// Count the number of ways to construct sum n by throwing a die one or more
// times. Each throw produces an outcome between 1 and  6.

static int count_dice_ways(int n)
{
	int result;
	int const mod = 1000000007;
	auto * dp = new uint64_t[n + 1];

	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp[i] = 0;
		for (uint8_t j = 1; j <= 6; ++j) {
			if (i - j < 0)
				break;
			dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}

	result = dp[n];
	delete[] dp;
	return result;
}

#if 0
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n_dice;
	cin >> n_dice;
	auto result = count_dice_ways(n_dice);
	cout << '\n' << result;
	return EXIT_SUCCESS;
}
#else
#include <gtest/gtest.h>

TEST(CSES1633, Example1) { EXPECT_EQ(count_dice_ways(3), 4); }

TEST(CSES1633, FailingCase1)
{
	int input = 50;
	int output = 660641036;
	EXPECT_EQ(count_dice_ways(input), output);
}

TEST(CSES1633, FailingCase2)
{
	int input = 50;
	int output = 660641036;
	EXPECT_EQ(count_dice_ways(input), output);
}

TEST(CSES1633, FailingCase3)
{
	int input = 1000;
	int output = 937196411;
	EXPECT_EQ(count_dice_ways(input), output);
}

TEST(CSES1633, FailingCase4)
{
	int input = 123456;
	int output = 113810539;
	EXPECT_EQ(count_dice_ways(input), output);
}

TEST(CSES1633, FailingCaseHuge)
{
	int input = 999997;
	int output = 74225807;
	EXPECT_EQ(count_dice_ways(input), output);
}

#endif
