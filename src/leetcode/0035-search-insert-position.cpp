#include <doctest/doctest.h>
#include <vector>

using namespace std;

int search_insert(std::vector<int> const & nums, int const target)
{
	int l = 0;
	int r = nums.size() - 1;
	int ip = nums.size();
	while (l <= r) {
		int m = (r + l) / 2;
		if (nums[m] >= target) {
			ip = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	return ip;
}

TEST_CASE("Example 1")
{
	vector<int> n { 1, 3, 5, 6 };
	REQUIRE_EQ(search_insert(n, 5), 2);
	REQUIRE_EQ(search_insert(n, 2), 1);
	REQUIRE_EQ(search_insert(n, 7), 4);
}