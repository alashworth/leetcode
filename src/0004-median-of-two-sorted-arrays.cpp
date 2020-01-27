#include <doctest/doctest.h>

#include <algorithm>
#include <vector>

using namespace std;
using doctest::Approx;

// preconditions:
//    v1 & v2 are sorted in ascending order
vector<int> merge(vector<int> const &v1, vector<int> const &v2) {
  vector<int> v3;
  auto it1 = v1.cbegin();
  auto it2 = v2.cbegin();

  while (true) {
    if (it1 == v1.cend() && it2 == v2.cend()) {
      return v3;
    } else if (it1 == v1.cend()) {
      copy(it2, v2.cend(), back_inserter(v3));
      return v3;
    } else if (it2 == v2.cend()) {
      copy(it1, v1.cend(), back_inserter(v3));
      return v3;
    } else {
      if (*it1 < *it2) {
        v3.emplace_back(*it1);
        ++it1;
      } else {
        v3.emplace_back(*it2);
        ++it2;
      }
    }
  }
}

double median(vector<int> const &v) {
  bool is_odd = v.size() % 2;
  if (is_odd) {
    return static_cast<double>(v[v.size() / 2]);
  } else {
    double med = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
    return med;
  }
}

TEST_CASE("4: merge works") {
  vector<int> a{1, 3}, b{2};
  vector<int> c = merge(a, b);
  CHECK_EQ(c, vector<int>{1, 2, 3});
}

TEST_CASE("4: median works") {
  vector<int> a{1, 3}, b{2};
  CHECK(median(merge(a, b)) == Approx(2));

  vector<int> c{1, 2}, d{3, 4};
  CHECK(median(merge(c, d)) == Approx(2.5));
}