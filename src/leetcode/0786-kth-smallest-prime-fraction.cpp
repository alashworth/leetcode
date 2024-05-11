#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<int> kspf(vector<int> & arr, int k)
{
	int n = arr.size();
	double left = 0, right = 1, mid;
	vector<int> res;

	while (left <= right) {
		mid = left + (right - left) / 2;
		int j = 1, total = 0, num = 0, den = 0;
		double maxFrac = 0;
		for (int i = 0; i < n; ++i) {
			while (j < n && arr[i] >= arr[j] * mid)
				++j;

			total += n - j;

			if (j < n && maxFrac < arr[i] * 1.0 / arr[j]) {
				maxFrac = arr[i] * 1.0 / arr[j];
				num = i;
				den = j;
			}
		}

		if (total == k) {
			res = { arr[num], arr[den] };
			break;
		}

		if (total > k) {
			right = mid;
		} else {
			left = mid;
		}
	}

	return res;
}

TEST(LC0786, Example1)
{
	vector in { 1, 2, 3, 5 };
	int k = 3;
	vector out = { 2, 5 };
	EXPECT_EQ(kspf(in, k), out);
}

TEST(LC0786, Example2)
{
	vector in { 1, 7 };
	int k = 1;
	vector out = { 1, 7 };
	EXPECT_EQ(kspf(in, k), out);
}

TEST(LC0786, FailingCase1)
{
	vector in { 1, 13, 17, 59 };
	int k = 6;
	vector out = { 13, 17 };
	EXPECT_EQ(kspf(in, k), out);
}