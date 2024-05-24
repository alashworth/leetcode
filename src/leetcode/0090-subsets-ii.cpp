#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<vector<int>> subsets_dup(vector<int> & n)
{
	vector<vector<int>> out;
	sort(n.begin(), n.end());

	size_t N = 1 << n.size();
	for (int i = 0; i < N; ++i) {
		out.emplace_back();
		size_t a = i;
		for (int j = 0; j < n.size(); ++j) {
			if (a >> j & 1) {
				out.back().push_back(n[j]);
			}
		}
	}
	sort(out.begin(), out.end());
	auto u = unique(out.begin(), out.end());
	out.erase(u, out.end());
	return out;
}

TEST(LC0090, Example1)
{
	vector nums { 1, 2, 2 };
	vector<vector<int>> expected { {}, { 1 }, { 1, 2 }, { 1, 2, 2 }, { 2 },
		{ 2, 2 } };
	EXPECT_EQ(subsets_dup(nums), expected);
}