#include <gtest/gtest.h>

using namespace std;

[[maybe_unused]] static int to_1d(int m, int n, int dim2sz)
{
	return m * dim2sz + n;
}

inline static pair<int, int> to_2d(int i, int dim2sz)
{
	int m = i / dim2sz;
	int n = i % dim2sz;
	return { m, n };
}

static bool search_matrix(vector<vector<int>> const & matrix, int target)
{
	int l = 0;
	int r = (int)(matrix.size() * matrix[0].size()) - 1;
	while (l <= r) {
		int m = (int)(((long long)l + (long long)r) / 2);
		auto [y, x] = to_2d(m, matrix[0].size());
		if (matrix[y][x] < target)
			l = m + 1;
		else if (matrix[y][x] > target)
			r = m - 1;
		else
			return true;
	}
	return false;
}

TEST(LC0074, Example1)
{
	vector<vector<int>> v { { 1, 3, 5, 7 }, { 10, 11, 16, 20 },
		{ 23, 30, 34, 60 } };
	int target = 3;
	EXPECT_TRUE(search_matrix(v, target));
}

TEST(LC0074, Singleton)
{
	vector<vector<int>> v {
		{ 1 },
	};
	int target = 1;
	EXPECT_TRUE(search_matrix(v, target));
}