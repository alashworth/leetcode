#include <cmath>
#include <doctest/doctest.h>
#include <numeric>
#include <vector>
#include <cstdint>

using std::vector;

// finds all prime numbers less than or equal to n
vector<int> sieve_of_eratosthenes(int n)
{
	vector<bool> A(n, true);
	int bnd = ceil(sqrt(n));
	for (int i = 2; i < bnd; ++i) {
		if (A[i]) {
			for (int j = i * i; j < n; j += i) {
				A[j] = false;
			}
		}
	}
	vector<int> result;
	result.reserve(n);
	for (int i = 2; i < A.size(); ++i) {
		if (A[i])
			result.push_back(i);
	}
	return result;
}

TEST_CASE("Sieve of Eratosthenes")
{
	auto v = sieve_of_eratosthenes(30);
	vector<int> ans { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	REQUIRE_EQ(v, ans);
}

TEST_CASE("Summation of primes.")
{
	{
		auto v = sieve_of_eratosthenes(10);
		auto r = std::reduce(v.begin(), v.end(), 0);
		REQUIRE_EQ(r, 17);
	}
	{
		auto v = sieve_of_eratosthenes(2'000'000);
		auto r = std::reduce(v.begin(), v.end(), uint64_t(0));
	}
}