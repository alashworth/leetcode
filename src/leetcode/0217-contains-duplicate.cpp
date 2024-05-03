#include <cstdlib>
#include <unordered_set>
#include <vector>

using namespace std;

int cmp(const void * a, const void * b)
{
	int * x = (int *)a;
	int * y = (int *)b;
	return *x - *y;
}

static bool contains_duplicate(int * nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);

	for (int i = 1; i < numsSize; ++i) {
		if (nums[i] == nums[i - 1])
			return true;
	}

	return false;
}

static bool contains_duplicate(vector<int> & nums)
{
	unordered_set<int> v;
	for (int i = 0; i < nums.size(); ++i) {
		v.insert(nums[i]);
		if (v.size() != i + 1)
			return true;
	}
	return false;
}