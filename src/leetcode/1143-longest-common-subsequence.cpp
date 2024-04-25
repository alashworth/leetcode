#include <gtest/gtest.h>

#include <string>

using namespace std;

static int lcs(string & text1, string & text2)
{
	int M = text1.size();
	int N = text2.size();
	int * d = new int[M * N];

	// base case - filling out first row and column
	d[0] = text1[0] == text2[0] ? 1 : 0;
	for (int i = 1; i < N; ++i)
		d[i] = text1[0] == text2[i] ? 1 : d[i - 1];

	for (int i = 1; i < M; ++i)
		d[i * N] = text1[i] == text2[0] ? 1 : d[(i - 1) * N];

	for (int m = 1; m < M; ++m) {
		for (int n = 1; n < N; ++n) {
			int idx = m * N + n;
			if (text1[m] == text2[n])
				d[idx] = d[idx - N - 1] + 1;
			else
				d[idx] = max(d[idx - 1], d[idx - N]);
		}
	}

	int cnt = d[M * N - 1];
	delete[] d;
	return cnt;
}

TEST(LC1143, Example1)
{
	string s1 { "abcde" };
	string s2 { "ace" };
	EXPECT_EQ(lcs(s1, s2), 3);
}

TEST(LC1143, Example2)
{
	string s1 { "abc" };
	string s2 { "abc" };
	EXPECT_EQ(lcs(s1, s2), 3);
}

TEST(LC1143, Example3)
{
	string s1 { "abc" };
	string s2 { "def" };
	EXPECT_EQ(lcs(s1, s2), 0);
}

TEST(LC1143, Sanitizer1)
{
	string s1 { "ezupkr" };
	string s2 { "ubmrapg" };
	EXPECT_EQ(lcs(s1, s2), 2);
}

TEST(LC1143, FailingCase1)
{
	string s1 { "bsbininm" };
	string s2 { "jmjkbkjkv" };
	EXPECT_EQ(lcs(s1, s2), 1);
}