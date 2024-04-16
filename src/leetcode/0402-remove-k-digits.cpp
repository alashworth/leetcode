#include <gtest/gtest.h>

#include <string>

using namespace std;

string remove_k_digits(string const & n, int const k)
{
	string stack;
	int remain = k;
	for (char c : n) {
		while (remain > 0 && !stack.empty() && stack.back() > c) {
			stack.pop_back();
			--remain;
		}
		stack += c;
	}

	while (remain > 0) {
		stack.pop_back();
		--remain;
	}

	auto cursor = stack.begin();
	while (cursor != stack.end() && *cursor == '0')
		++cursor;

	string result = stack.substr(distance(stack.begin(), cursor));
	return result.empty() ? "0" : result;
}

TEST(LC0402, Example1)
{
	string n { "1432219" };
	int k = 3;
	auto rv = remove_k_digits(n, k);
	EXPECT_EQ(rv, "1219");
}

TEST(LC0402, Example2)
{
	string n { "10200" };
	int k = 1;
	auto rv = remove_k_digits(n, k);
	EXPECT_EQ(rv, "200");
}

TEST(LC0402, Example3)
{
	string n { "10" };
	int k = 2;
	auto rv = remove_k_digits(n, k);
	EXPECT_EQ(rv, "0");
}