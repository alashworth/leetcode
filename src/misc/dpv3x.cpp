#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

vector<vector<int>> parse_edge_list(
	int N, vector<pair<int, int>> const & e, bool undirected = false)
{
	vector<vector<int>> rv(N, vector<int> {});

	for (auto const [u, v] : e) {
		rv[u].push_back(v);
		if (undirected)
			rv[v].push_back(u);
	}

	// sort and remove duplicates from each edge list
	for (auto & v : rv) {
		ranges::sort(v);
		auto [first, last] = ranges::unique(v);
		v.erase(first, last);
	}
	return rv;
}

void explore(const vector<vector<int>> & G, int v, vector<bool> & visited,
	int & clock, vector<int> & pre, vector<int> & post)
{
	visited[v] = true;
	pre[v] = clock++;
	for (auto & e : G[v]) {
		if (!visited[e])
			explore(G, e, visited, clock, pre, post);
	}
	post[v] = clock++;
}

pair<vector<int>, vector<int>> dfs(const vector<vector<int>> & graph)
{
	auto const N = graph.size();
	vector<bool> visited(N, false);
	int clock = 1;
	vector<int> pre(N, 0);
	vector<int> post(N, 0);
	for (int i = 0; i < N; ++i) {
		if (!visited[i])
			explore(graph, i, visited, clock, pre, post);
	}

	return { pre, post };
}

vector<vector<int>> reverse(vector<vector<int>> const & graph)
{
	auto N = graph.size();
	vector<vector<int>> reversed(N, vector<int> {});
	for (int i = 0; i < N; ++i) {
		for (auto edge : graph[i]) { }
	}
}

TEST_SUITE_BEGIN("DPV3X");

TEST_CASE("FIG3_7")
{
	vector<pair<int, int>> const edges { { 0, 1 }, { 0, 2 }, { 0, 5 }, { 1, 4 },
		{ 2, 3 }, { 3, 0 }, { 3, 7 }, { 4, 5 }, { 4, 6 }, { 4, 7 }, { 5, 1 },
		{ 5, 6 }, { 7, 6 } };
	auto const G = parse_edge_list(8, edges);
	auto [pre, post] = dfs(G);
	REQUIRE_EQ(pre, vector { 1, 2, 12, 13, 3, 4, 5, 8 });
	REQUIRE_EQ(post, vector { 16, 11, 15, 14, 10, 7, 6, 9 });
}

TEST_CASE("EX3_3")
{
	vector<pair<int, int>> const edges { { 0, 2 }, { 1, 2 }, { 2, 3 }, { 2, 4 },
		{ 3, 5 }, { 4, 5 }, { 5, 6 }, { 5, 7 } };
	auto const G = parse_edge_list(8, edges);
	auto [pre, post] = dfs(G);
	REQUIRE_EQ(pre, vector { 1, 15, 2, 3, 11, 4, 5, 7 });
	REQUIRE_EQ(post, vector { 14, 16, 13, 10, 12, 9, 6, 8 });
}

TEST_SUITE_END();