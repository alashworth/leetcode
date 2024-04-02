#include <gtest/gtest.h>

#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int msl(vector<int> & n, int k)
{
	auto left = n.begin();
	auto right = n.begin();
	unordered_map<int, int> freq;
	int lopt = 1;

	while (true) {
		// grow window to the right
		while (right != n.end()) {
			if (freq.contains(*right)) {
				if (freq[*right] == k) {
					break;
				} else {
					freq[*right]++;
				}
			} else {
				freq.emplace(*right, 1);
			}
			right += 1;
		}

		lopt = max(lopt, (int)distance(left, right));

		// pop the left
		freq[*left]--;
		left += 1;

		if (left == n.end())
			break;
	}

	return lopt;
}

TEST(LC2958, Example1)
{
	vector<int> x { 1, 2, 3, 1, 2, 3, 1, 2 };
	EXPECT_EQ(msl(x, 2), 6);
}

TEST(LC2958, FailingTestCase1)
{
	vector<int> x { 1, 11 };
	EXPECT_EQ(msl(x, 2), 2);
}