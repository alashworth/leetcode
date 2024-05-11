#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

long long max_happiness_sum(vector<int> & happiness, int k)
{
	make_heap(happiness.begin(), happiness.end());

	long long sum = 0;
	long long penalty = 0;
	for (auto n { ssize(happiness) }; n >= 0; --n) {
		ranges::pop_heap(happiness.begin(), happiness.begin() + n);
		auto maxval = *(happiness.cbegin() + n - 1);
		if (maxval <= penalty)
			break;
		sum += maxval - penalty;
		penalty++;
		k--;
		if (k <= 0)
			break;
	}
	return sum;
}

TEST(LC3075, Example1)
{
	vector h { 1, 2, 3 };
	int k = 2;
	long long out = 4;
	EXPECT_EQ(max_happiness_sum(h, k), out);
}

TEST(LC3075, Example2)
{
	vector h { 1, 1, 1, 1 };
	int k = 2;
	long long out = 1;
	EXPECT_EQ(max_happiness_sum(h, k), out);
}

TEST(LC3075, Example3)
{
	vector h { 2, 3, 4, 5 };
	int k = 1;
	long long out = 5;
	EXPECT_EQ(max_happiness_sum(h, k), out);
}

TEST(LC3075, FailingCase1)
{
	vector h { 12, 1, 42 };
	int k = 3;
	long long out = 53;
	EXPECT_EQ(max_happiness_sum(h, k), out);
}