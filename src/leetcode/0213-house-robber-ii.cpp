#include <gtest/gtest.h>

#include <vector>

using namespace std;

static int rob(vector<int> const & n)
{
	auto const N = n.size();
	if (N == 1)
		return n[0];
	if (N == 2)
		return max(n[0], n[1]);

	vector<int> odd(N, 0);
	vector<int> even(N, 0);

	odd[0] = n[0];
	odd[1] = odd[0];
	even[1] = n[1];

	for (int i = 2; i < N - 1; ++i) {
		odd[i] = max(odd[i - 2] + n[i], odd[i - 1]);
		even[i] = max(even[i - 2] + n[i], even[i - 1]);
	}

	odd[N - 1] = odd[N - 2];
	even[N - 1] = max(even[N - 3] + n[N - 1], even[N - 2]);

	return max(even[N - 1], odd[N - 1]);
}

TEST(LC0213, Example1)
{
	vector<int> n { 2, 3, 2 };
	EXPECT_EQ(rob(n), 3);
}

TEST(LC0213, Example2)
{
	vector<int> n { 1, 2, 3, 1 };
	EXPECT_EQ(rob(n), 4);
}

TEST(LC0213, Example3)
{
	vector<int> n { 1, 2, 3 };
	EXPECT_EQ(rob(n), 3);
}