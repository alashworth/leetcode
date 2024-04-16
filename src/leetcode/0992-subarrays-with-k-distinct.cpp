#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

using namespace std;

vector<int> min_window_k_distinct(vector<int> const & n, int k)
{
	unordered_map<int, int> s;
	vector<int> r(n.size(), 0);
	int ixs = 0;
	for (int i = 0; i < n.size(); ++i) {
		s[n[i]]++;
		while (s.size() >= k) {
			if (s[n[ixs]] > 1) {
				s[n[ixs]]--;
			} else {
				s.erase(n[ixs]);
			}
			++ixs;
		}
		r[i] = ixs;
	}
	return r;
}

int subarray_k_distinct(vector<int> const & n, int k)
{
	int n_good = 0;
	auto aa = min_window_k_distinct(n, k);
	auto bb = min_window_k_distinct(n, k + 1);
	for (int i = 0; i < n.size(); ++i) {
		n_good += aa[i] - bb[i];
	}
	return n_good;
}

TEST(LC0992, Example1)
{
	vector<int> n { 1, 2, 1, 2, 3 };
	EXPECT_EQ(subarray_k_distinct(n, 2), 7);
}

TEST(LC0992, Example2)
{
	vector<int> n { 1, 2, 1, 3, 4 };
	EXPECT_EQ(subarray_k_distinct(n, 3), 3);
}

TEST(LC0992, FailingCase1)
{
	vector<int> n { 7, 9, 6, 10, 3, 7, 6, 14, 9, 14, 7, 6, 13, 5 };
	EXPECT_EQ(subarray_k_distinct(n, 4), 16);
}