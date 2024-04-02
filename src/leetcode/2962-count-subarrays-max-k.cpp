#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

long long subrange_cnt_ge_k(vector<int> const & n, int k)
{
	int mx = ranges::max(n);
	auto N = n.size();
	long long subarray_cnt = 0;
	int k_cnt = 0;
	int j = 0;

	for (int i = 0; i < N; ++i) {
		while (j < N && k_cnt < k) {
			k_cnt += (n[j] == mx ? 1 : 0);
			++j;
		}

		if (k_cnt < k)
			break;

		subarray_cnt += N - j + 1;

		k_cnt -= (n[i] == mx ? 1 : 0);
	}

	return subarray_cnt;
}

TEST(LC2962, Example1)
{
	vector<int> n { 1, 3, 2, 3, 3 };
	int k = 2;
	EXPECT_EQ(subrange_cnt_ge_k(n, k), 6);
}

TEST(LC2962, Example2)
{
	vector<int> n { 1, 4, 2, 1 };
	int k = 3;
	EXPECT_EQ(subrange_cnt_ge_k(n, k), 0);
}

TEST(LC2962, FailingCase1)
{
	vector<int> n { 61, 23, 38, 23, 56, 40, 82, 56, 82, 82, 82, 70, 8, 69, 8, 7,
		19, 14, 58, 42, 82, 10, 82, 78, 15, 82 };
	int k = 2;
	EXPECT_EQ(subrange_cnt_ge_k(n, k), 224);
}

TEST(LC2962, FailingCase2)
{
	vector<int> n { 37, 20, 38, 66, 34, 38, 9, 41, 1, 14, 25, 63, 8, 12, 66, 66,
		60, 12, 35, 27, 16, 38, 12, 66, 38, 36, 59, 54, 66, 54, 66, 48, 59, 66,
		34, 11, 50, 66, 42, 51, 53, 66, 31, 24, 66, 44, 66, 1, 66, 66, 29, 54 };
	int k = 5;
	EXPECT_EQ(subrange_cnt_ge_k(n, k), 594);
}