#include <doctest/doctest.h>
#include <vector>

using namespace std;

// dynamic programming solution
int max_subarray(vector<int> const & n)
{
	int m1 = n[0];
	int m2 = n[0];
	for (int i = 1; i < n.size(); ++i) {
		m1 = max(n[i], n[i] + m1);
		m2 = max(m1, m2);
	}
	return m2;
}

TEST_CASE("Simple cases.")
{
	vector const t1 { 1 };
	vector const t2 { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	vector const t3 { 5, 4, -1, 7, 8 };

	REQUIRE_EQ(max_subarray(t1), 1);
	REQUIRE_EQ(max_subarray(t2), 6);
	REQUIRE_EQ(max_subarray(t3), 23);
}