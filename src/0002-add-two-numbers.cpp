#include <doctest/doctest.h>

#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *add_aux(ListNode *l1, ListNode *l2, int c) {
  if (l1 == nullptr && l2 == nullptr) {
    if (c > 0) {
      auto v = new ListNode(c);
      return v;
    }
    return nullptr;
  } else if (l1 != nullptr && l2 == nullptr) {
    int rv = l1->val + c;
    c = 0;
    while (rv >= 10) {
      rv -= 10;
      c += 1;
    }
    auto v = new ListNode(rv);
    v->next = add_aux(l1->next, nullptr, c);
    return v;
  } else if (l1 == nullptr && l2 != nullptr) {
    int rv = l2->val + c;
    c = 0;
    while (rv >= 10) {
      rv -= 10;
      c += 1;
    }
    auto v = new ListNode(rv);
    v->next = add_aux(nullptr, l2->next, c);
    return v;
  } else { /* l1 != nullptr && l2 != nullptr */
    int rv = l1->val + l2->val + c;
    c = 0;
    while (rv >= 10) {
      rv -= 10;
      c += 1;
    }
    auto v = new ListNode(rv);
    v->next = add_aux(l1->next, l2->next, c);
    return v;
  }
}

ListNode *add_two_numbers(ListNode *l1, ListNode *l2) {
  return add_aux(l1, l2, 0);
}

TEST_CASE("2: solution passes example") {
  ListNode a1(2), a2(4), a3(3);
  ListNode b1(5), b2(6), b3(4);
  a1.next = &a2;
  a2.next = &a3;
  b1.next = &b2;
  b2.next = &b3;
  auto result = add_two_numbers(&a1, &b1);
  REQUIRE_EQ(result->val, 7);
  REQUIRE_EQ(result->next->val, 0);
  REQUIRE_EQ(result->next->next->val, 8);
  REQUIRE_EQ(result->next->next->next, nullptr);
}

TEST_CASE("2: handle carry list expansion") {
  ListNode a1(5), b1(5);
  auto result = add_two_numbers(&a1, &b1);
  REQUIRE_EQ(result->val, 0);
  REQUIRE_NE(result->next, nullptr);
  REQUIRE_EQ(result->next->val, 1);
}