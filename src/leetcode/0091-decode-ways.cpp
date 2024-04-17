#include <gtest/gtest.h>

#include <string>

using namespace std;

int n_decodings(string const & s) { return 0; }

TEST(LC0091, Example1) { EXPECT_EQ(n_decodings("12"), 2); }

TEST(LC0091, Example2) { EXPECT_EQ(n_decodings("226"), 3); }

TEST(LC0091, Example3) { EXPECT_EQ(n_decodings("06"), 0); }