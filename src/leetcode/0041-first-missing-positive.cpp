#include <gtest/gtest.h>

#include <vector>

using namespace std;

int fmp(vector<int> & n)
{
	// modified cycle sort
	size_t N = n.size();
	for (int i = 1; i <= N; i++) {
		while (i != n[i - 1]) {
			int j = n[i - 1];
			if (1 > j || j >= N || j == n[j - 1])
				break;
			swap(n[j - 1], n[i - 1]);
		}
	}

	for (int i = 0; i < N; ++i) {
		if (n[i] != i + 1) {
			return i + 1;
		}
	}

	return N + 1;
}

TEST(LC0041, Example1)
{
	vector<int> nums = { 1, 2, 0 };
	EXPECT_EQ(fmp(nums), 3);
};

TEST(LC0041, Example2)
{
	vector<int> nums = { 3, 4, -1, 1 };
	EXPECT_EQ(fmp(nums), 2);
}

TEST(LC0041, Example3)
{
	vector<int> nums = { 7, 8, 9, 11, 12 };
	EXPECT_EQ(fmp(nums), 1);
}

TEST(LC0041, Example4)
{
	vector<int> nums = { 1 };
	EXPECT_EQ(fmp(nums), 2);
}
