#include <doctest/doctest.h>

// Given a linked list, remove the n-th node from the end of list and return its
// head.

struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int x)
		: val { x }
		, next { nullptr }
	{
	}
};

ListNode* remove_nth_from_end(ListNode* head, int n)
{
	if (head == nullptr || head->next == nullptr) {
		return nullptr;
	}
	auto x = head;
	int cnt = 1;
	ListNode *nth = head, *nth_prev = head;
	while (x->next != nullptr) {
		if (cnt == n) {
			nth_prev = nth;
			nth = nth->next;
			--cnt;
		}
		++cnt, x = x->next;
	}
	nth_prev->next = nth->next;
	if (nth == head) {
		return head->next;
	} else {
		return head;
	}
}

TEST_CASE("leetcode example")
{
	ListNode n1 { 1 }, n2 { 2 }, n3 { 3 }, n4 { 4 }, n5 { 5 };
	n1.next = &n2, n2.next = &n3, n3.next = &n4, n4.next = &n5;
	int n = 2;
	auto p = remove_nth_from_end(&n1, n);
	CHECK_EQ(p->val, 1);
	CHECK_EQ(p->next->val, 2);
	CHECK_EQ(p->next->next->val, 3);
	CHECK_EQ(p->next->next->next->val, 5);
	CHECK_EQ(p->next->next->next->next, nullptr);
}

TEST_CASE("Singular list")
{
	ListNode n1 { 1 };
	int n = 1;
	auto p = remove_nth_from_end(&n1, n);
	CHECK_EQ(p, nullptr);
}

TEST_CASE("Remove head")
{
	ListNode n1 { 1 }, n2 { 2 };
	n1.next = &n2;
	int n = 2;
	auto p = remove_nth_from_end(&n1, n);
	CHECK_EQ(2, p->val);
}