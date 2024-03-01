#include <doctest/doctest.h>

#include <bits/stdc++.h>
using namespace std;

// L ← Empty list that will contain the sorted nodes
// while exists nodes without a permanent mark do
// 	select an unmarked node n
// 	visit(n)
//
// function visit(node n)
// 	if n has a permanent mark then
// 		return
// 	if n has a temporary mark then
// 		stop   (graph has at least one cycle)
//
// 	mark n with a temporary mark
//
// 	for each node m with an edge from n to m do
// 		visit(m)
//
// 	remove temporary mark from n
// 	mark n with a permanent mark
// 	add n to head of L

enum Color : char { white, grey, black };

vector<int> toposort(vector<vector<int>> G)
{
	int N = 8;
	vector<Color> c(N, white);
	vector<int> p(N, -1);
	vector<int> d(N, -1);
	vector<int> f(N, -1);
	int clock = 0;

	vector<int> seq;
	stack<pair<int, int>> S;
	for (int i = 0; i < N; ++i) {
		if (c[i] == white) {
			// dfsvisit
			c[i] = grey;
			p[i] = -1;
			// clock++;
			// d[i] = clock;
			S.emplace(i, 1);
			while (!S.empty()) {
				auto [u, k] = S.top();
				S.pop();
				if (k <= G[u].size()) {
					S.emplace(u, k + 1);
					auto v = G[u][k - 1];
					if (c[v] == white) {
						c[v] = grey;
						p[v] = u;
						clock++;
						d[u] = clock;
						S.emplace(v, 1);
					}
				} else {
					c[u] = black;
					clock++;
					f[u] = clock;
					seq.push_back(u);
				}
			}
		}
	}
	return seq;
}

TEST_CASE("dpv33-topo")
{
	int N = 8;
	vector<vector<int>> G {
		{ 2 }, // A-0
		{ 2 }, // B-1
		{ 3, 4 }, // C-2
		{ 5 }, // D-3
		{ 5 }, // E-4
		{ 6, 7 }, // F-5
		{}, // G-6
		{}, // H-7
	};
	auto rv = toposort(G);
}