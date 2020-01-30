#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

using namespace std;
// You are given a square 2D matrix representing an image.
// Rotate the image by 90 degrees (clockwise).
//
// Note:
// Must rotate matrix in-place.

void transpose(vector<vector<int>>& matrix) {
    for (auto i = 0; i < matrix.size(); ++i) {
        for (auto j = i + 1; j < matrix[i].size(); ++j) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

TEST_CASE("transpose") {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    transpose(matrix);
    vector<vector<int>> expected{{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    CHECK_EQ(expected, matrix);
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    for (auto& v : matrix) { reverse(begin(v), end(v)); }
}

TEST_CASE("example 1") {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    vector<vector<int>> expected{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
    CHECK_EQ(expected, matrix);
}

TEST_CASE("example 2") {
    vector<vector<int>> matrix{
            {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(matrix);
    vector<vector<int>> expected{
            {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};
    CHECK_EQ(expected, matrix);
}