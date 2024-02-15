#include <doctest/doctest.h>

#include <vector>

using namespace std;

/* 1. Define entries in words.
 * 2. State recurrence in terms of smaller subproblems.
 * 3. Write code.
 * 4. Give runtime analysis.
 */

int max_sum_subsequence(vector<int> const& in)
{
	// 1. Let T(i) be the maximum sum that includes in[i].
	// 2.	T(1) = in(1)
	//		T(i) = max(in(i), in(i) + T(i-1)
	if (in.empty())
		return 0;
	int sum = in[0];
	for (auto const x : in)
		sum = max(x, x + sum);
	return sum;
	// 4. for x : in -> O(n)
}

TEST_CASE("Simple Example")
{
	vector<int> const x {5, 15, -30, 10, -5, 40, 10};
	REQUIRE_EQ(max_sum_subsequence(x), 55);
}

TEST_CASE("Boundary Conditions")
{
	vector<int> const empty {};
	REQUIRE_EQ(max_sum_subsequence(empty), 0);
}