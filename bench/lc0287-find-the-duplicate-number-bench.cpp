#include <benchmark/benchmark.h>

#include <algorithm>
#include <array>
#include <numeric>
#include <random>
#include <vector>

using namespace std;
namespace bm = benchmark;

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

int floyd(vector<int> const & nums)
{
	int tortoise = nums[nums[0] - 1] - 1;
	int hare = nums[nums[nums[0] - 1] - 1] - 1;

	while (tortoise != hare) {
		tortoise = nums[tortoise] - 1;
		hare = nums[nums[hare] - 1] - 1;
	}

	int mu = 0;
	tortoise = nums[0] - 1;
	while (tortoise != hare) {
		tortoise = nums[tortoise] - 1;
		hare = nums[hare] - 1;
		++mu;
	}

	return mu;
}

static const int N = 10000;

static void bench_binsearch(bm::State & state)
{
	vector<int> arr;
	arr.reserve(N);
	iota(arr.begin(), arr.end(), 1);

	random_device rd;
	std::mt19937 gen(rd());
	uniform_int_distribution<int> distribution(1, N);

	int r1 = distribution(gen);
	int r2 = distribution(gen);
	int r3 = distribution(gen);

	if (r3 < r2)
		swap(r2, r3);

	fill_n(arr.begin(), r3 - r2, r1);
	shuffle(arr.begin(), arr.end(), gen);

	for (auto _ : state) {
		find_duplicate(arr);
	}
}
