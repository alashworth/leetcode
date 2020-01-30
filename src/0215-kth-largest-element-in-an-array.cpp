#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

using namespace std;

// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.

int kth_largest(vector<int>& nums, int k) {
    k--;
    nth_element(begin(nums), nums.begin() + k, end(nums), greater<int>());
    return nums[k];
}

TEST_CASE("Example 1") {
    vector<int> input{3,2,1,5,6,4};
    int k = 2;
    CHECK_EQ(kth_largest(input, k), 5);
}