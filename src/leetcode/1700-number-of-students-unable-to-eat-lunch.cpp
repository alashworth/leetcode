#include <gtest/gtest.h>

#include <numeric>
#include <vector>

using namespace std;

int count_students(vector<int> const & students, vector<int> const & sandwiches)
{
	int square_students = accumulate(students.begin(), students.end(), 0);
	int circle_students = students.size() - square_students;

	for (int sandwich : sandwiches) {
		(sandwich == 0) ? --circle_students : --square_students;
		if (square_students < 0)
			return circle_students;
		if (circle_students < 0)
			return square_students;
	}
	return 0;
}

TEST(LC1700, Example1)
{
	vector<int> stu { 1, 1, 0, 0 };
	vector<int> san { 0, 1, 0, 1 };
	EXPECT_EQ(count_students(stu, san), 0);
}

TEST(LC1700, Example2)
{
	vector<int> stu { 1, 1, 1, 0, 0, 1 };
	vector<int> san { 1, 0, 0, 0, 1, 1 };
	EXPECT_EQ(count_students(stu, san), 3);
}