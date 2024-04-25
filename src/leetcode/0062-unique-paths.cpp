#include <gtest/gtest.h>

using namespace std;

static int unique_paths(int M, int N)
{
	int * t = new int[M * N];

	// bottom row is 1
	for (int n = (M - 1) * N; n < M * N; ++n) {
		t[n] = 1;
	}

	// right column is 1
	for (int m = N - 1; m < M * N - 1; m += N) {
		t[m] = 1;
	}

	for (int m = M - 2; m >= 0; --m) {
		for (int n = N - 2; n >= 0; --n) {
			t[m * N + n] = t[m * N + n + 1] + t[(m + 1) * N + n];
		}
	}

	int cnt = t[0];
	delete[] t;
	return cnt;
}

TEST(LC0062, Examples)
{
	EXPECT_EQ(unique_paths(3, 7), 28);
	EXPECT_EQ(unique_paths(3, 2), 3);
}