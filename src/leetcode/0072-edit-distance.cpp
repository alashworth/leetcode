#include <doctest/doctest.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Given two words word1 and word2, find the minimum number of operations
// required to convert word1 to word2.
//
// You have the following 3 operations permitted on a word:
//
// Insert a character
// Delete a character
// Replace a character

// this problem is equal to calculating the Levenshtein distance
// which is defined by:
// let i = |a|, j = |b|,
// let ind = 0 if a_i = b_j else 1
// if min(i,j) = 0 then max(i,j)
// min(
//    lev(i-1,j) + ind
//    lev(i,j-1) + ind
//    lev(i-1,j-1) + ind
// )

inline int ind(char a, char b) { return a == b ? 0 : 1; }

int lev1_aux(string const& a, string const& b, size_t i, size_t j)
{
	if (min(i, j) == 0) {
		return max(i, j);
	} else {
		auto w = ind(a[i - 1], b[j - 1]);
		auto x = lev1_aux(a, b, i - 1, j) + w;
		auto y = lev1_aux(a, b, i, j - 1) + w;
		auto z = lev1_aux(a, b, i - 1, j - 1) + w;
		return min(x, min(y, z));
	}
}

int lev1(string const& a, string const& b)
{
	auto i = a.length(), j = b.length();
	if (min(i, j) == 0) {
		return max(i, j);
	} else {
		return lev1_aux(a, b, i, j);
	}
}

// lev1 + memoization
int lev2_aux(string const& a, string const& b, int i, int j)
{
	auto w = ind(a[i - 1], b[j - 1]);

	auto x = lev1_aux(a, b, i - 1, j) + w;
	auto y = lev1_aux(a, b, i, j - 1) + w;
	auto z = lev1_aux(a, b, i - 1, j - 1) + w;

	return min(x, min(y, z));
}

int lev2(string const& a, string const& b)
{
	int m = a.length(), n = b.length();
	vector<vector<int>> d(m + 1);

	// zero initialize vector
	for (int i = 0; i <= m; ++i) {
		d[i].assign(n + 1, 0);
	}

	// we know the first column...
	for (int i = 1; i <= m; ++i) {
		d[i][0] = i;
	}

	// and the first row
	for (int j = 1; j <= n; ++j) {
		d[0][j] = j;
	}

	for (int j = 1; j <= n; ++j) {
		for (int i = 1; i <= m; ++i) {
			int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
			d[i][j] = min(
				min(d[i - 1][j] + 1, d[i][j - 1] + 1), d[i - 1][j - 1] + cost);
		}
	}
	return d[m][n];
}

TEST_CASE("Wikipedia example") { CHECK_EQ(3, lev1("kitten", "sitting")); }

TEST_CASE("Leetcode example 1") { CHECK_EQ(3, lev1("horse", "ros")); }

TEST_CASE("Leetcode example 2") { CHECK_EQ(5, lev1("intention", "execution")); }

TEST_CASE("Lev2 Wikipedia") { CHECK_EQ(3, lev2("sitting", "kitten")); }