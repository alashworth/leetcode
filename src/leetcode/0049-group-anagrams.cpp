#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <string>
#include <vector>

using namespace std;

const int N_LETTERS = 26;

static array<short, N_LETTERS> histogram(string & s)
{
	array<short, N_LETTERS> hist = { 0 };
	for (char i : s) {
		auto idx = i - 97;
		hist[idx] += 1;
	}
	return hist;
}

vector<vector<string>> groupAnagrams(vector<string> & strs)
{
	vector<array<short, N_LETTERS>> hists;
	hists.reserve(strs.size());

	// calculate histogram for each string
	for (auto & s : strs) {
		hists.emplace_back(histogram(s));
	}

	// determine and assign group number to each string
	int cnt = 0;
	vector<int> numbering(strs.size(), -1);
	vector<int> group_size;
	group_size.reserve(strs.size());
	for (int i = 0; i < hists.size(); ++i) {
		// if string has been evaluated, skip
		if (numbering[i] != -1)
			continue;
		numbering[i] = cnt;
		group_size.push_back(0);
		for (int j = i + 1; j < hists.size(); ++j) {
			bool eq = equal(hists[i].begin(), hists[i].end(), hists[j].begin());
			if (eq) {
				numbering[j] = cnt;
				group_size.back() += 1;
			}
		}
		++cnt;
	}

	// build the return value
	vector<vector<string>> grouping(cnt);
	for (int k = 0; k < strs.size(); ++k) {
		int grpnum = numbering[k];
		grouping[grpnum].emplace_back(strs[k]);
	}

	return grouping;
}

// TEST(LC0049, Example1)
//{
//	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
//	vector<vector<string>> out = { { "bat" }, { "nat", "tan" },
//		{ "ate", "eat", "tea" } };
//	auto rv = groupAnagrams(strs);
//	for (int i = 0; i < min(strs.size(), out.size()); ++i) {
//		EXPECT_EQ(rv[i], out[i]);
//	}
// }