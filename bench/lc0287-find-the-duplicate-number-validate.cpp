#include <gtest/gtest.h>

#include <vector>

using namespace std;

int find_duplicate(vector<int> const & nums);
int floyd(vector<int> const & nums);

TEST(LC0287, RefExample1)
{
	vector<int> n { 1, 3, 4, 2, 2 };
	EXPECT_EQ(find_duplicate(n), 2);
}

TEST(LC0287, RefExample2)
{
	vector<int> n { 3, 1, 3, 4, 2 };
	EXPECT_EQ(find_duplicate(n), 3);
}

TEST(LC0287, RefExample3)
{
	vector<int> n { 3, 3, 3, 3, 3 };
	EXPECT_EQ(find_duplicate(n), 3);
}

TEST(LC0287, RefExample4)
{
	vector<int> n { 1, 4, 4, 2, 4 };
	EXPECT_EQ(find_duplicate(n), 4);
}

TEST(LC0287, FloydExample1)
{
	vector<int> n { 1, 3, 4, 2, 2 };
	EXPECT_EQ(floyd(n), 2);
}

TEST(LC0287, FloydExample2)
{
	vector<int> n { 3, 1, 3, 4, 2 };
	EXPECT_EQ(floyd(n), 3);
}

TEST(LC0287, FloydExample3)
{
	vector<int> n { 3, 3, 3, 3, 3 };
	EXPECT_EQ(floyd(n), 3);
}

TEST(LC0287, FloydExample4)
{
	vector<int> n { 1, 4, 4, 2, 4 };
	EXPECT_EQ(floyd(n), 4);
}