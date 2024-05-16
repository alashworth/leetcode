#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<vector<int>> subsets(vector<int> & nums)
{
	vector<vector<int>> rv;
	unsigned short N = 1 << nums.size(); // max(N) = 1024
	rv.reserve(N);
	for (int i = 0; i < N; ++i) {
		rv.emplace_back();
		for (unsigned char j = 0; j < nums.size(); ++j) {
			if (i >> j & 1) {
				rv[i].emplace_back(nums[j]);
			}
		}
	}
	return rv;
}