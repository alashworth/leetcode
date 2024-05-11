#include <gtest/gtest.h>

#include <deque>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode()
		: val(0)
		, next(nullptr)
	{
	}
	explicit ListNode(int x)
		: val(x)
		, next(nullptr)
	{
	}
	ListNode(int x, ListNode * next)
		: val(x)
		, next(next)
	{
	}
};

ListNode * remove_nodes(ListNode * head)
{
	deque<int> deq;

	auto cursor = head;
	while (cursor != nullptr) {
		auto v = cursor->val;
		while (!deq.empty() && deq.front() < v) {
			deq.pop_front();
		}
		deq.push_front(v);
		cursor = cursor->next;
	}

	for (cursor = head; cursor != nullptr; cursor = cursor->next) {
		auto v = deq.back();
		cursor->val = v;
		deq.pop_back();
		if (deq.empty()) {
			cursor->next = nullptr;
			break;
		}
	}

	return head;
}

// TEST(LC2487, Example1)
//{
//	vector<ListNode> nodes(5);
//	nodes[4] = ListNode(8);
//	nodes[3] = ListNode(3, &nodes[4]);
//	nodes[2] = ListNode(13, &nodes[3]);
//	nodes[1] = ListNode(2, &nodes[2]);
//	nodes[0] = ListNode(5, &nodes[1]);
//
//	auto head = remove_nodes(&nodes[0]);
// }