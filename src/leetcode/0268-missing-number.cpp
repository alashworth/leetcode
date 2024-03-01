#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

// see related problems 0448 and 0041

int missing_no(vector<int> & n)
{
	size_t N = n.size();
	for (int i = 0; i < N; i++) {
		while (i != n[i]) {
			if (n[i] >= N)
				break;
			swap(n[n[i]], n[i]);
		}
	}
	for (int i = 0; i < N; i++) {
		if (i != n[i]) {
			return i;
		}
	}
	return N;
}

TEST_SUITE("0268-missing-number")
{
	TEST_CASE("Example 1")
	{
		vector<int> n { 3, 0, 1 };
		REQUIRE_EQ(missing_no(n), 2);
	}

	TEST_CASE("Example 2")
	{
		vector<int> n { 0, 1 };
		REQUIRE_EQ(missing_no(n), 2);
	}

	TEST_CASE("Example 3")
	{
		vector<int> n { 9, 6, 4, 2, 3, 5, 7, 0, 1 };
		REQUIRE_EQ(missing_no(n), 8);
	}
}
