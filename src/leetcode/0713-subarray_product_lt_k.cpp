#include <gtest/gtest.h>

using namespace std;

int n_sub_prod_lt_k(vector<int> & n, int const k)
{
	vector<int> opt(n.size(), 0);
	for (int i = 1; i < n.size(); ++i) {
		int sum = n[i];
		for (int j = i - 1; j >= 0; --j) {
			sum *= n[j];
			if (sum < k) {
				opt[i]++;
			} else {
				break;
			}
		}
	}

	int accum = 0;
	for (int i = 0; i < n.size(); ++i) {
		accum += opt[i];
		if (n[i] < k)
			accum++;
	}

	return accum;
}

TEST(LC0713, Example1)
{
	vector<int> n { 10, 5, 2, 6 };
	int k = 100;
	EXPECT_EQ(n_sub_prod_lt_k(n, k), 8);
}