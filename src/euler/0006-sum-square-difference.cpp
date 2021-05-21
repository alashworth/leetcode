#include <cstdint>
#include <doctest/doctest.h>

uint64_t sum_of_squares(int n)
{
	uint64_t accum = 0;
	for (int i = 1; i <= n; ++i) {
		accum += i * i;
	}
	return accum;
}

uint64_t square_of_sums(int n)
{
	uint64_t tmp = (n + 1) * n / 2;
	return tmp * tmp;
}

template <typename T>
T abs_diff(T a, T b)
{
	return (a > b) ? (a - b) : (b - a);
}

TEST_CASE("Sum square difference example.")
{
	auto n = 10;
	auto a = sum_of_squares(n);
	REQUIRE_EQ(a, 385);
	auto b = square_of_sums(n);
	REQUIRE_EQ(b, 3025);
	auto diff = abs_diff(a, b);
	REQUIRE_EQ(diff, 2640);
}

TEST_CASE("Testing diff.")
{
	auto n = 100;
	auto a = sum_of_squares(n);
	auto b = square_of_sums(n);
	REQUIRE_EQ(b, 25502500);
	uint64_t diff = (a > b) ? (a - b) : (b - a);
	MESSAGE(diff);
}