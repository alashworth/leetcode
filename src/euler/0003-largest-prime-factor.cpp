#include <doctest/doctest.h>

#include <algorithm>
#include <cstdint>
#include <type_traits>
#include <vector>

using namespace std;

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

TEST_CASE("Trial division works on example.")
{
	int n = 13195;
	vector<int> ans { 5, 7, 13, 29 };
	auto sol = trial_div(n);
	REQUIRE_EQ(sol, ans);
}

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143?
TEST_CASE("Trial division works on problem.")
{
	int_fast64_t constexpr num = 600851475143;
	auto sol = trial_div(num);
	auto max_elem = *max_element(sol.begin(), sol.end());
	REQUIRE_EQ(max_elem, 6857);
}