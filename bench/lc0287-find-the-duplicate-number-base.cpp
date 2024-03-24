#include <numeric>
#include <vector>

using namespace std;

int find_duplicate(vector<int> const & nums)
{
	// Initialize the search range
	int left = 0;
	int right = static_cast<int>(nums.size()) - 1;

	// Use binary search to find the duplicate
	while (left < right) {
		// Find the midpoint of the current search range
		int mid = left + (right - left) / 2;

		// Count how many numbers are less than or equal to 'mid'
		int count = 0;
		for (int num : nums) {
			if (num <= mid) {
				count++;
			}
		}

		// If the count is more than 'mid', then the duplicate is in the left
		// half
		if (count > mid) {
			right = mid; // Search in the left half
		} else {
			left = mid + 1; // Search in the right half
		}
	}

	// 'left' is the duplicate number
	return left;
}

int floyd(vector<int> const & n)
{
	int tortoise = n[0];
	int hare = n[n[0]];

	while (tortoise != hare) {
		tortoise = n[tortoise];
		hare = n[n[hare]];
	}

	tortoise = 0;
	while (tortoise != hare) {
		tortoise = n[tortoise];
		hare = n[hare];
	}

	return hare;
}