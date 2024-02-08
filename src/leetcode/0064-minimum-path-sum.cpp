#include <doctest/doctest.h>
#include <limits>
#include <vector>

using namespace std;

// Given a m x n grid filled with non-negative numbers, find a path from top
// left to bottom right, which minimizes the sum of all numbers along its path.
// Note : You can only move either down or right at any point in time.

int min_path_sum(vector<vector<int>> const & grid)
{
	// this is just shortest paths. the natural topological ordering is left to
	// right, top to bottom, or vice versa

	auto M = grid.size();
	auto N = grid[0].size();

	vector<vector<int>> d(M, vector<int>(N, numeric_limits<int>::max()));

	d[0][0] = grid[0][0];
	for (size_t i = 0; i < M; ++i) {
		for (size_t j = 0; j < N; ++j) {
			// iterate over tiles above and to the left
			if (i > 0)
				d[i][j] = min(d[i - 1][j] + grid[i][j], d[i][j]);
			if (j > 0)
				d[i][j] = min(d[i][j - 1] + grid[i][j], d[i][j]);
		}
	}
	return d[M - 1][N - 1];
}

TEST_CASE("MPS Example 1")
{
	REQUIRE_EQ(7, min_path_sum({ { 1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } }));
}