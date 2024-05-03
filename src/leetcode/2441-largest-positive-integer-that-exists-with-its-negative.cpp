#include <algorithm>
#include <vector>

using namespace std;

int find_max_k(vector<int> & nums)
{
	struct {
		bool operator()(int a, int b) const { return abs(a) > abs(b); }
	} custom_gt;

	sort(nums.begin(), nums.end(), custom_gt);

	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] == (-1 * nums[i - 1]))
			return abs(nums[i]);
	}
	return -1;
}