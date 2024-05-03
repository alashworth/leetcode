#include <gtest/gtest.h>

#include <cstdlib>

int compare_version(char * v1, char * v2)
{
	char *end1, *end2;
	int a, b;

	a = strtol(v1, &end1, 10);
	b = strtol(v2, &end2, 10);
	if (a < b)
		return -1;
	if (a > b)
		return 1;

	while (*end1 == '.' && *end2 == '.') {
		a = strtol(end1 + 1, &end1, 10);
		b = strtol(end2 + 1, &end2, 10);
		if (a < b)
			return -1;
		if (a > b)
			return 1;
	}

	while (*end1 == '.') {
		a = strtol(end1 + 1, &end1, 10);
		if (a > 0)
			return 1;
	}

	while (*end2 == '.') {
		b = strtol(end2 + 1, &end2, 10);
		if (b > 0)
			return -1;
	}

	return 0;
}

TEST(LC0165, Example1)
{
	char a[] = "1.01";
	char b[] = "1.001";
	auto out = 0;
	EXPECT_EQ(compare_version(a, b), out);
}

TEST(LC0165, Example2)
{
	char a[] = "1.0";
	char b[] = "1.0.0";
	auto out = 0;
	EXPECT_EQ(compare_version(a, b), out);
}

TEST(LC0165, Example3)
{
	char a[] = "0.1";
	char b[] = "1.1";
	auto out = -1;
	EXPECT_EQ(compare_version(a, b), out);
}

TEST(LC0165, FailingCase1)
{
	char a[] = "1.0.1";
	char b[] = "1";
	auto out = 1;
	EXPECT_EQ(compare_version(a, b), out);
}