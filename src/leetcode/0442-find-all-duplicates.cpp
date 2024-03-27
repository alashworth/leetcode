#include <gtest/gtest.h>

#include <vector>

using namespace std;

vector<int> find_duplicates(vector<int> & nums)
{
	vector<int> result {};
	auto f = [&](int i) -> int & { return nums[i - 1]; };
	for (int i = 1; i <= nums.size(); ++i) {
		while (i != f(i)) {
			if (f(i) == f(f(i)))
				break;
			swap(f(i), f(f(i)));
		}
	}

	for (int i = 0; i < nums.size(); ++i) {
		if (i + 1 != nums[i]) {
			result.push_back(nums[i]);
		}
	}

	// Why does this have to be in sorted order? This doesn't count for O(n).
	sort(result.begin(), result.end());
	return result;
}

TEST(LC0442, findAllDuplicates)
{
	vector<int> n { 4, 3, 2, 7, 8, 2, 3, 1 };
	EXPECT_EQ(find_duplicates(n), (vector<int> { 2, 3 }));
}