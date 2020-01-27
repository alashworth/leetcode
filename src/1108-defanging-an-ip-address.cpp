#include <doctest/doctest.h>

#include <string>

using namespace std;

// Given a valid (IPv4) IP address, return a defanged version of that IP
// address.
//
// A defanged IP address replaces every period "." with "[.]".
string defang_IP_address(string addr) {
  size_t old_size = addr.size();
  addr.resize(old_size + 6);
  ssize_t i = static_cast<ssize_t>(old_size) - 1;
  auto j = old_size + 5;
  while(i >= 0) {
    if(addr[static_cast<size_t>(i)] == '.') {
      addr[j] = ']';
      addr[j-1] = '.';
      addr[j-2] = '[';
      j -= 3;
      --i;
    } else {
      swap(addr[static_cast<size_t>(i)], addr[j]);
      --i;
      --j;
    }
  }
  return addr;
}

TEST_CASE("Example 1") {
  CHECK_EQ(defang_IP_address("1.1.1.1"), "1[.]1[.]1[.]1");
}

TEST_CASE("Example 2") {
  CHECK_EQ(defang_IP_address("255.100.50.0"), "255[.]100[.]50[.]0");
}