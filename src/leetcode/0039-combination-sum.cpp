#include <gtest/gtest.h>

#include <algorithm>
#include <numeric>
#include <span>
#include <vector>

using namespace std;

void backtrack(
	vector<int> & c, int r, int i, vector<int> & p, vector<vector<int>> & o)
{
	if (r < 0 || i >= c.size())
		return;
	if (r == 0) {
		o.push_back(p);
		return;
	}
	p.push_back(c[i]);
	r = r - c[i];
	backtrack(c, r, i, p, o);
	r += p.back();
	p.pop_back();
	backtrack(c, r, i + 1, p, o);
}

vector<vector<int>> combinationSum(vector<int> & candidates, int target)
{
	candidates.erase(remove_if(candidates.begin(), candidates.end(),
						 [target](int v) { return v > target; }),
		candidates.end());

	sort(candidates.begin(), candidates.end());
	vector<vector<int>> out;

	vector<int> partial;
	backtrack(candidates, target, 0, partial, out);
	return out;
}

TEST(LC0039, Example1)
{
	vector c { 2, 3, 5 };
	int t = 8;
	vector<vector<int>> expected { { 2, 2, 2, 2 }, { 2, 3, 3 }, { 3, 5 } };
	EXPECT_EQ(combinationSum(c, t), expected);
}