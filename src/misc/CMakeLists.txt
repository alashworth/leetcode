add_executable(misc
        ../util/algorithms.cpp
        cses-1633-dice-combinations.cpp
)

target_link_libraries(misc PRIVATE GTest::gtest_main)