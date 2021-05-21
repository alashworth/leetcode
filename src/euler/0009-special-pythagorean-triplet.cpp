#include <cstdint>
#include <doctest/doctest.h>

uint64_t find_pythagorean_triplet(int total)
{
	for (int a = 1; a <= total; ++a) {
		for (int b = a + 1; b <= total; ++b) {
			for (int c = b + 1; c < total; ++c)
				if (a + b + c == total && a * a + b * b == c * c) {
					return a * b * c;
				}
		}
	}
	return 0;
}

TEST_CASE("Special Pythagorean triplet.")
{
	auto v = find_pythagorean_triplet(12);
	REQUIRE_EQ(v, 60);
	auto x = find_pythagorean_triplet(1000);
	MESSAGE(x);
}