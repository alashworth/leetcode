#include <gtest/gtest.h>

#include <stack>
#include <string>

using namespace std;

bool is_valid(string & str)
{
	stack<char> stk;
	for (auto c : str) {
		if (c == '(' || c == '{' || c == '[') {
			stk.push(c);
			continue;
		}

		if (c == ')') {
			if (stk.empty() || stk.top() != '(') {
				return false;
			}
			stk.pop();
		}

		if (c == '}') {
			if (stk.empty() || stk.top() != '{') {
				return false;
			}
			stk.pop();
		}

		if (c == ']') {
			if (stk.empty() || stk.top() != '[') {
				return false;
			}
			stk.pop();
		}
	}

	if (stk.empty()) {
		return true;
	}
	return false;
}

TEST(LC0020, Example1)
{
	string s { "()" };
	EXPECT_TRUE(is_valid(s));
}

TEST(LC0020, FailingCase1)
{
	string s { "){" };
	EXPECT_FALSE(is_valid(s));
}