#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

vector<string> find_relative_ranks(vector<int> & score)
{
	vector<int> indices(score.size());
	iota(indices.begin(), indices.end(), 0);

	sort(indices.begin(), indices.end(),
		[&](int a, int b) { return score[b] < score[a]; });

	vector<string> answer(indices.size());
	for (int i = 0; i < indices.size(); ++i) {
		int j = indices[i];
		if (i == 0)
			answer[j] = "Gold Medal";
		else if (i == 1)
			answer[j] = "Silver Medal";
		else if (i == 2)
			answer[j] = "Bronze Medal";
		else
			answer[j] = to_string(i + 1);
	}

	return answer;
}

TEST(LC0506, Example1)
{
	vector score { 5, 4, 3, 2, 1 };
	vector<string> output { "Gold Medal", "Silver Medal", "Bronze Medal", "4",
		"5" };
	EXPECT_EQ(find_relative_ranks(score), output);
}

TEST(LC0506, Example2)
{
	vector score { 10, 3, 8, 9, 4 };
	vector<string> output { "Gold Medal", "5", "Bronze Medal", "Silver Medal",
		"4" };
	EXPECT_EQ(find_relative_ranks(score), output);
}