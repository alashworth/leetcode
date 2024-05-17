#include <gtest/gtest.h>
#include <vector>

using namespace std;

int search(int * n, int sz, int v)
{
	int l = 0;
	int r = sz - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (n[m] < n[0])
			r = m - 1;
		else
			l = m + 1;
	}

	if (l == sz) {
		l = 0;
		r = sz - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (n[m] == v)
				return m;
			if (n[m] < v)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}

	bool in_lhs = n[0] <= v;
	if (in_lhs) {
		r = l - 1;
		l = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (n[m] == v)
				return m;
			if (n[m] < v)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	} else {
		r = sz - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (n[m] == v)
				return m;
			if (n[m] < v)
				l = m + 1;
			else
				r = m - 1;
		}
		return -1;
	}
}

TEST(LC0033, Example1)
{
	vector<int> nums { 4, 5, 6, 7, 0, 1, 2 };
	int target = 0;
	EXPECT_EQ(search(nums.data(), nums.size(), target), 4);
}

TEST(LC0033, Example2)
{
	vector<int> nums { 1, 2, 3, 4, 5, 6, 7 };
	int target = 1;
	EXPECT_EQ(search(nums.data(), nums.size(), target), 0);
}

TEST(LC0033, Test3)
{
	vector<int> nums { 1, 2, 3, 4, 5, 6, 7 };
	int target = 0;
	EXPECT_EQ(search(nums.data(), nums.size(), target), -1);
}

TEST(LC0033, Singleton)
{
	vector<int> nums { 1 };
	int target = 1;
	EXPECT_EQ(search(nums.data(), nums.size(), target), 0);
}

TEST(LC0033, Two)
{
	vector<int> nums { 1, 3 };
	int target = 3;
	EXPECT_EQ(search(nums.data(), nums.size(), target), 1);
}