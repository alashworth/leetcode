#include <algorithm>
#include <doctest/doctest.h>
#include <limits>
#include <vector>

using namespace std;

/* 1. Define entries in words.
 * 2. State recurrence in terms of smaller subproblems.
 * 3. Write code.
 * 4. Give runtime analysis.
 */

int yuckdonalds1(vector<int> const & m, vector<int> const & p, int k)
{
	// O(n^2) solution
	int n = m.size();
	vector<int> d(n, numeric_limits<int>::min());
	d[0] = p[0];
	for (int i = 1; i < n; ++i) {
		d[i] = p[i];
		for (int j = 0; j < i; ++j) {
			if (m[i] - m[j] >= k) {
				if (d[j] + p[i] > d[i]) {
					d[i] = d[j] + p[i];
				}
			}
		}
	}
	return ranges::max(d);
}

TEST_CASE("Simple Example")
{
	vector<int> m = { 0, 4, 8 };
	vector<int> p = { 10, 42, 31 };
	int k = 5;
	REQUIRE_EQ(yuckdonalds1(m, p, k), 42);
}

TEST_CASE("Greedy Conditions")
{
	vector<int> m = { 10, 20, 25, 30, 40 };
	vector<int> p = { 100, 100, 101, 100, 100 };
	int k = 10;
	REQUIRE_EQ(yuckdonalds1(m, p, k), 400);
}

TEST_CASE("An Example")
{
	vector<int> m = { 0, 5, 6, 11, 14, 20, 22, 28 };
	vector<int> p = { 30, 10, 40, 1, 15, 5, 23, 17 };
	int k = 5;
	REQUIRE_EQ(yuckdonalds1(m, p, k), 108);
}