add_library(lc0287-base lc0287-find-the-duplicate-number-base.cpp)

add_executable(lc0287-validate lc0287-find-the-duplicate-number-validate.cpp)
target_link_libraries(lc0287-validate PUBLIC lc0287-base GTest::gtest_main)

add_executable(lc0287-bench lc0287-find-the-duplicate-number-bench.cpp)
target_link_libraries(lc0287-bench PUBLIC lc0287-base benchmark::benchmark_main)