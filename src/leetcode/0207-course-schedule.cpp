#include <doctest/doctest.h>

#include <stack>
#include <vector>

using namespace std;

enum Color : char { white, grey, black };

bool finishable(int const N, vector<vector<int>> const & E)
{
	// form the graph
	vector<vector<int>> G(N, vector<int>());
	for (auto e : E) {
		int m = e[0];
		int n = e[1];
		G[m].push_back(n);
	}

	vector<Color> c(N, white);
	vector<int> p(N, -1);
	vector<int> d(N, -1);
	vector<int> f(N, -1);
	int clock = 0;
	for (int i = 0; i < N; ++i) {
		if (c[i] == white) {
			stack<pair<int, int>> S;
			c[i] = grey;
			S.emplace(i, 1);
			clock++;
			d[i] = clock;
			while (!S.empty()) {
				auto [u, k] = S.top();
				S.pop();
				if (G[u].size() >= k) {
					S.emplace(u, k + 1);
					auto v = G[u][k - 1];
					if (c[v] == white) {
						c[v] = grey;
						p[v] = u;
						d[u] = clock;
						S.emplace(v, 1);
					} else if (c[v] == grey) {
						goto back_edge;
					}
				} else {
					c[u] = black;
					clock++;
					f[u] = clock;
				}
			}
		}
	}
	return true;
back_edge:
	return false;
}

TEST_CASE("Course schedule example 1")
{
	bool const f = finishable(2, { { 1, 0 } });
	REQUIRE_EQ(f, true);
}

TEST_CASE("Course schedule example 2")
{
	bool const f = finishable(2, { { 1, 0 }, { 0, 1 } });
	REQUIRE_EQ(f, false);
}

TEST_CASE("Course schedule example 3")
{
	bool const f = finishable(2, { { 0, 1 } });
	REQUIRE_EQ(f, true);
}
