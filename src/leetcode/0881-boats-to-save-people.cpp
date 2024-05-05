#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

using namespace std;

int n_rescue_boats(vector<int> & people, int limit)
{
	int n_boats = 0;
	sort(people.begin(), people.end());

	int l = 0, r = people.size() - 1;
	while (l <= r) {
		if (people[l] + people[r] <= limit) {
			n_boats++, l++, r--;
		} else {
			n_boats++, r--;
		}
	}

	return n_boats;
}

TEST(LC0881, Example1)
{
	vector p { 1, 2 };
	int l = 3;
	EXPECT_EQ(n_rescue_boats(p, l), 1);
}

TEST(LC0881, Example2)
{
	vector p { 3, 2, 2, 1 };
	int l = 3;
	EXPECT_EQ(n_rescue_boats(p, l), 3);
}

TEST(LC0881, Example3)
{
	vector p { 3, 5, 3, 4 };
	int l = 5;
	EXPECT_EQ(n_rescue_boats(p, l), 4);
}