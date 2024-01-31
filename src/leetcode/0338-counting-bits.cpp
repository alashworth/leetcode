#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

using namespace std;

vector<int> count_bits(int const n)
{
	vector<int> b(n + 1);
	b[0] = 0;

	for (unsigned int i = 1; i < n + 1; ++i) {
		auto offset = i & (i - 1);
		b[i] = b[offset] + 1;
	}

	return b;
}

TEST_CASE("Example 1")
{
	auto ans = count_bits(2);
	vector<int> expected { 0, 1, 1 };
	REQUIRE(ranges::equal(ans, expected));
}