#include <gtest/gtest.h>

#include <vector>

using namespace std;

using vec = std::vector<int>;
using vvec = std::vector<std::vector<int>>;

static void backtrack(vec & c, int pos, int t, vec & p, vvec & o)
{
	if (t < 0)
		return;
	if (t == 0) {
		o.push_back(p);
		return;
	}
	int prev = -1;
	for (int i = pos; i < c.size(); ++i) {
		if (c[i] == prev)
			continue;
		p.push_back(c[i]);
		backtrack(c, i + 1, t - c[i], p, o);
		p.pop_back();
		prev = c[i];
	}
}

static vector<vector<int>> csum2(vector<int> & candidates, int target)
{
	sort(candidates.begin(), candidates.end());
	vec p;
	vvec out;
	backtrack(candidates, 0, target, p, out);
	return out;
}

TEST(LC0040, Example1)
{
	vector<int> in { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;
	vector<vector<int>> out { { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } };
	EXPECT_EQ(csum2(in, target), out);
}

TEST(LC0040, TLE)
{
	vector<int> in { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1 };
	int target = 27;
	vector<vector<int>> out { { in } };
	EXPECT_EQ(csum2(in, target), out);
}