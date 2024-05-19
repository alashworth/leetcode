#include <gtest/gtest.h>

#include <queue>

using namespace std;

class MedianFinder {
public:
	void addNum(int num)
	{
		if (low.empty() && high.empty())
			low.push(num);
		else if (low.empty() && !high.empty()) {
			if (num <= high.top())
				low.push(num);
			else {
				low.push(high.top());
				high.pop();
				high.push(num);
			}
		} else if (!low.empty() && high.empty()) {
			if (num >= low.top())
				high.push(num);
			else {
				high.push(low.top());
				low.pop();
				low.push(num);
			}
		} else if (!low.empty() && !high.empty()) {
			if (num <= low.top())
				low.push(num);
			else {
				high.push(num);
			}
		}
		while (!low.empty() && high.size() < low.size() - 1) {
			high.push(low.top());
			low.pop();
		}
		while (!high.empty() && low.size() < high.size() - 1) {
			low.push(high.top());
			high.pop();
		}
	}
	double findMedian()
	{
		if ((low.size() + high.size()) % 2 == 0) {
			auto m1 = static_cast<double>(low.top());
			auto m2 = static_cast<double>(high.top());
			return (m1 + m2) / 2;
		} else {
			if (low.size() > high.size())
				return low.top();
			else {
				return high.top();
			}
		}
	}

private:
	priority_queue<int, vector<int>, less<>> low;
	priority_queue<int, vector<int>, greater<>> high;
};

TEST(LC0295, Example1)
{
	auto mf = MedianFinder();
	mf.addNum(1);
	mf.addNum(2);
	EXPECT_DOUBLE_EQ(mf.findMedian(), 1.5);
	mf.addNum(3);
	EXPECT_DOUBLE_EQ(mf.findMedian(), 2.0);
}

TEST(LC0295, TestCase4)
{
	auto mf = MedianFinder();
	mf.addNum(-1.0);
	EXPECT_DOUBLE_EQ(mf.findMedian(), -1.0);
	mf.addNum(-2.0);
	EXPECT_DOUBLE_EQ(mf.findMedian(), -1.5);
	mf.addNum(-3.0);
	EXPECT_DOUBLE_EQ(mf.findMedian(), -2.0);
	mf.addNum(-4.0);
	EXPECT_DOUBLE_EQ(mf.findMedian(), -2.5);
	mf.addNum(-5.0);
	EXPECT_DOUBLE_EQ(mf.findMedian(), -3.0);
}