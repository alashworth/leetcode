#include <doctest/doctest.h>

#include <algorithm>
#include <array>
#include <string>

using namespace std;

// Given a string, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
bool is_palindrome(string s)
{
	size_t i = 0;
	size_t j = !s.empty() ? s.size() - 1 : 0;
	while (i < j) {
	incr_front:
		auto front = toupper(s[i]);
		if (!isalnum(front)) {
			i++;
			if (i < j) {
				goto incr_front;
			} else {
				break;
			}
		}

	incr_back:
		auto back = toupper(s[j]);
		if (!isalnum(back)) {
			j--;
			if (i < j) {
				goto incr_back;
			} else {
				break;
			}
		}

		if (front == back) {
			i++;
			j--;
			continue;
		} else {
			return false;
		}
	}
	return true;
}

TEST_CASE("Example 1")
{
	CHECK(is_palindrome("A man, a plan, a canal: Panama"));
}

TEST_CASE("Example 2") { CHECK(!is_palindrome("race a car")); }

TEST_CASE("Punctuation") { CHECK(is_palindrome(".,")); }