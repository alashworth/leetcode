#include <gtest/gtest.h>

#include <queue>
#include <vector>

using namespace std;

double mchw(vector<int> & quality, vector<int> & wage, int k)
{
	vector<pair<double, int>> ratio;
	int n = quality.size();

	for (int i = 0; i < n; ++i) {
		ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
	}

	sort(begin(ratio), end(ratio));
	priority_queue<int> maxHeap;
	int qualitySum = 0;
	double maxRate = 0.0;

	for (int i = 0; i < k; ++i) {
		qualitySum += quality[ratio[i].second];
		maxRate = max(maxRate, ratio[i].first);
		maxHeap.push(quality[ratio[i].second]);
	}

	double res = maxRate * qualitySum;
	for (int i = k; i < n; ++i) {
		maxRate = max(maxRate, ratio[i].first);
		qualitySum -= maxHeap.top();
		maxHeap.pop();

		qualitySum += quality[ratio[i].second];
		maxHeap.push(quality[ratio[i].second]);
		res = min(res, maxRate * qualitySum);
	}

	return res;
}

TEST(LC0857, Example1)
{
	vector quality { 10, 20, 5 };
	vector wage { 70, 50, 30 };
	int k = 2;
	double out = 105.00000;
	EXPECT_DOUBLE_EQ(mchw(quality, wage, k), out);
}