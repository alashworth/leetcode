#include <cstdint>
#include <doctest/doctest.h>
#include <vector>

using std::vector;

template <typename T>
vector<T> trial_div(T n)
{
	static_assert(std::is_integral<T>::value, "Integral required.");
	vector<T> acc;
	while (n % 2 == 0) {
		acc.push_back(2);
		n /= 2;
	}
	T f = 3;
	while (f * f <= n) {
		if (n % f == 0) {
			acc.push_back(f);
			n /= f;
		} else {
			f += 2;
		}
	}
	if (n != 1) {
		acc.push_back(n);
	}
	return acc;
}

bool is_prime(uint64_t n)
{
	auto v = trial_div(n);
	return v.size() == 1;
}

uint64_t nth_prime(uint64_t n)
{
	int i = 2;
	int primecnt = 0;
	for (; primecnt < n; ++i) {
		if (is_prime(i))
			++primecnt;
	}
	return i - 1;
}

TEST_CASE("Nth prime examples.")
{
	REQUIRE_EQ(nth_prime(1), 2);
	REQUIRE_EQ(nth_prime(2), 3);
	REQUIRE_EQ(nth_prime(3), 5);
	REQUIRE_EQ(nth_prime(4), 7);
	REQUIRE_EQ(nth_prime(5), 11);
	REQUIRE_EQ(nth_prime(6), 13);
}
