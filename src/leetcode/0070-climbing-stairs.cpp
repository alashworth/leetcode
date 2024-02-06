#include <doctest/doctest.h>

using namespace std;

// You are climbing a staircase with n stairs. Each step, you climb either
// 1 or 2 steps. How many distinct paths are there to the top?

// Example: 4
// 1111
// 112
// 121
// 211
// 22

// This is a dynamic programming problem, because it has subproblems we can
// exploit. The number of distinct paths for n steps is the number of paths
// for n-2 + the number of paths for n-1. Observe that for n-2 we can add a two
// step, and for n-1 we can add a 1 step, and together those make up all the
// ways we could get to the nth step.
// This is the Fibonacci sequence in disguise, let's pretend we don't know
// the closed form solution.

int climb_stairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 3;

	int f[n];
	f[0] = 1;
	f[1] = 2;
	f[2] = 3;
	for (int i = 3; i < n; ++i)
		f[i] = f[i - 1] + f[i - 2];

	return f[n-1];
}

TEST_CASE("Simple Tests")
{
	REQUIRE_EQ(climb_stairs(2), 2);
	REQUIRE_EQ(climb_stairs(3), 3);
}
