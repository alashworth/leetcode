#include <gtest/gtest.h>

#include <vector>

using namespace std;

static int matrix_score(vector<vector<int>> & grid)
{
	for (auto & row : grid) {
		if (row[0] == 0) {
			for (auto & e : row) {
				e = 1 - e;
			}
		}
	}

	for (int i = 1; i < grid[0].size(); ++i) {
		int n_zeros = 0;
		for (auto & e : grid) {
			n_zeros += 1 - e[i];
		}
		if (n_zeros > grid.size() / 2) {
			for (auto & e : grid) {
				e[i] = 1 - e[i];
			}
		}
	}

	int total_sum = 0;
	for (auto & row : grid) {
		int row_number = 0;
		for (auto e : row) {
			row_number = (row_number << 1) + e;
		}
		total_sum += row_number;
	}

	return total_sum;
}

TEST(LC0861, Example1)
{
	vector<vector<int>> grid { { 0, 0, 1, 1 }, { 1, 0, 1, 0 }, { 1, 1, 0, 0 } };

	EXPECT_EQ(matrix_score(grid), 39);
}