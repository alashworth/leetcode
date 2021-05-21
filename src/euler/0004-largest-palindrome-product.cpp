#include <doctest/doctest.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// A palindromic number reads the same both ways. The largest palindrome made
// from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.
bool is_palindrome(int n)
{
	string s = to_string(n);
	string r(s.rbegin(), s.rend());
	return s == r;
}

struct largest_palindrome_res {
	int f1;
	int f2;
	int pal;
};

largest_palindrome_res largest_palindrome(int n_digits)
{
	vector<largest_palindrome_res> acc;
	int mval = 0;
	for (auto i = 0; i < n_digits; ++i) {
		mval = 10 * mval + 9;
	}
	for (auto i = mval; i > 0; --i) {
		for (auto j = i; j > 0; --j) {
			auto num = i * j;
			if (is_palindrome(num)) {
				acc.emplace_back(largest_palindrome_res { i, j, num });
			}
		}
	}
	auto biggest = *max_element(acc.begin(), acc.end(),
		[](auto a, auto b) -> bool { return a.pal < b.pal; });
	return biggest;
}

TEST_CASE("Testing is_palindrome.") { REQUIRE_EQ(is_palindrome(9801), false); }

TEST_CASE("Testing largest palindrome example.")
{
	auto r = largest_palindrome(2);
	CHECK_EQ(r.f1, 99);
	CHECK_EQ(r.f2, 91);
	CHECK_EQ(r.pal, 9009);
}

TEST_CASE("Testing largest palindrome.")
{
	auto r = largest_palindrome(3);
	REQUIRE_EQ(r.pal, 906609);
}