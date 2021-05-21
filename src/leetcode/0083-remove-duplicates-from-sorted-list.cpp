#include <doctest/doctest.h>

#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	explicit ListNode(int x)
		: val(x)
		, next(nullptr)
	{
	}
};

ListNode* remove_duplicates(ListNode* hd)
{
	if (hd == nullptr || (hd->next == nullptr))
		return hd;

	auto x = hd, xs = hd->next;
	bool dup = false;
	for (;;) {
		if (xs == nullptr) {
			if (dup) {
				x->next = nullptr;
			}
			break;
		} else if (x->val == xs->val) {
			dup = true;
			xs = xs->next;
		} else { // x->val != xs->val
			if (dup) {
				x->next = xs, dup = false;
			}
			x = xs;
			xs = xs->next;
		}
	}
	return hd;
}

TEST_CASE("tc1")
{
	ListNode n1(1), n2(1), n3(2), n4(3), n5(3);
	n1.next = &n2, n2.next = &n3, n3.next = &n4, n4.next = &n5;
	remove_duplicates(&n1);
	CHECK_EQ(n1.val, 1);
	CHECK_EQ(n1.next->val, 2);
	CHECK_EQ(n1.next->next->val, 3);
	CHECK_EQ(n1.next->next->next, nullptr);
}