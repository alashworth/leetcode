#include <sltbench/Bench.h>

#include "../src/0072-edit-distance.cpp"

void bench_lev1() {
  string s1{"Pneumonoultramicroscopicsilicovolcanoconiosis"};
  string s2{"Pseudopseudohypoparathyroidism "};
  lev1(s1, s2);
}

void bench_lev2() {
  string s1{"Pneumonoultramicroscopicsilicovolcanoconiosis"};
  string s2{"Pseudopseudohypoparathyroidism "};
  lev2(s1, s2);
}

SLTBENCH_FUNCTION(bench_lev1);
SLTBENCH_FUNCTION(bench_lev2);

SLTBENCH_MAIN();