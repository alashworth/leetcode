#include <doctest/doctest.h>

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// given a string, find the longest substring without repeating characters

int length_of_longest_substring(string s) {
  if (s.empty()) {
    return 0;
  }
  vector<char> substr, best_substr{s[0]};

  for (size_t i = 0; i < s.size(); ++i) {
    substr.clear();
    for (size_t j = i; j < s.size(); ++j) {
      auto p = find(substr.begin(), substr.end(), s[j]);
      if (p == substr.end()) {
        substr.emplace_back(s[j]);
        if (substr.size() > best_substr.size()) {
          best_substr = substr;
        }
        continue;
      } else {
        break;
      }
    }
  }
  return static_cast<int>(best_substr.size());
}

TEST_CASE("3: solution passes examples") {
  string s1("abcabcbb");
  string s2("bbbbb");
  string s3("pwwkew");
  string s4(" ");
  string s5("au");

  CHECK_EQ(length_of_longest_substring(s1), 3);
  CHECK_EQ(length_of_longest_substring(s2), 1);
  CHECK_EQ(length_of_longest_substring(s3), 3);
  CHECK_EQ(length_of_longest_substring(s4), 1);
  CHECK_EQ(length_of_longest_substring(s5), 2);
}