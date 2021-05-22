#include <doctest/doctest.h>
#include <vector>

using std::vector;

int gcd(int m, int n)
{
	int tmp;
	while (m) {
		tmp = m;
		m = n % m;
		n = tmp;
	}
	return n;
}

int lcm(int m, int n) { return m / gcd(m, n) * n; }

int lcm_range(int n)
{
	int ans = 1;
	for (int i = 2; i <= n; ++i) {
		ans = lcm(ans, i);
	}
	return ans;
}

// 2520 is the smallest number that can be divided by each of the numbers from 1
// to 10 without any remainder.
TEST_CASE("Testing smallest multiple example.")
{
	auto ans = lcm_range(10);
	REQUIRE_EQ(ans, 2520);
}

// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20?
TEST_CASE("Testing smallest multiple.")
{
	auto ans = lcm_range(20);
}