#include <bits/stdc++.h>
#include <doctest/doctest.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode()
		: val(0)
		, left(nullptr)
		, right(nullptr)
	{
	}
	explicit TreeNode(int const x)
		: val(x)
		, left(nullptr)
		, right(nullptr)
	{
	}
	TreeNode(int const x, TreeNode * left, TreeNode * right)
		: val(x)
		, left(left)
		, right(right)
	{
	}
};

void inorder(TreeNode * root, vector<int> & n)
{
	if (root == nullptr)
		return;

	inorder(root->left, n);
	n.push_back(root->val);
	inorder(root->right, n);
}

bool is_valid_bst(TreeNode * root)
{
	vector<int> n;
	inorder(root, n);
	return ranges::is_sorted(n, ranges::less_equal {});
}

TEST_SUITE("0094-validate-binary-search-tree")
{
	TEST_CASE("Example 1")
	{
		array<TreeNode, 3> t { TreeNode(1, nullptr, nullptr),
			TreeNode(3, nullptr, nullptr), TreeNode(2, &t[0], &t[1]) };
		REQUIRE(is_valid_bst(&t[2]));
	}
	TEST_CASE("Example 2")
	{
		array<TreeNode, 5> t {
			TreeNode(1, nullptr, nullptr),
			TreeNode(3, nullptr, nullptr),
			TreeNode(6, nullptr, nullptr),
			TreeNode(4, &t[1], &t[2]),
			TreeNode(5, &t[0], &t[3]),
		};
		REQUIRE_FALSE(is_valid_bst(&t[4]));
	}
	TEST_CASE("Example 3")
	{
		array<TreeNode, 3> t { TreeNode(2, nullptr, nullptr),
			TreeNode(2, nullptr, nullptr), TreeNode(2, &t[0], &t[1]) };
		REQUIRE_FALSE(is_valid_bst(&t[2]));
	}
}