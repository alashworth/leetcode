#include <cstdlib>

struct ListNode {
	int val;
	struct ListNode * next;
};

static struct ListNode * reverse(struct ListNode * const head)
{
	struct ListNode *prv, *cur, *nxt;

	prv = 0;
	cur = head;
	nxt = head->next;
	while (true) {
		cur->next = prv;
		prv = cur;
		if (nxt != 0) {
			cur = nxt;
			nxt = nxt->next;
		} else {
			break;
		}
	}
	return prv;
}

static struct ListNode * double_it(struct ListNode * head)
{
	struct ListNode *cur, *sav, *tmp;

	cur = reverse(head);
	sav = cur;

	int carry = 0;
	while (cur != 0) {
		int v = cur->val * 2 + carry;
		carry = v / 10;
		int rem = v % 10;
		cur->val = rem;
		tmp = cur;
		cur = cur->next;
	}
	if (carry > 0) {
		struct ListNode * n =
			(struct ListNode *)(malloc(sizeof(struct ListNode)));
		n->val = carry;
		n->next = 0;
		tmp->next = n;
	}

	cur = reverse(sav);
	return cur;
}