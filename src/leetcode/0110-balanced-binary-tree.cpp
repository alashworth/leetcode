#include <gtest/gtest.h>

struct TreeNode {
	int val;
	struct TreeNode * left;
	struct TreeNode * right;
};

typedef struct TreeNode TreeNode;
static bool balanced = true;

int maxDepth(struct TreeNode * root)
{
	if (!root) {
		return 0;
	}
	int left = maxDepth(root->left);
	int right = maxDepth(root->right);

	int diff = left - right;
	if ((diff < -1) || (diff > 1)) {
		balanced = false;
	}

	return (left < right ? right + 1 : left + 1);
}

bool isBalanced(struct TreeNode * root)
{
	if (!root)
		return true;
	maxDepth(root);
	return balanced;
}

TEST(LC0110, FailingCase1)
{
	TreeNode root = { .val = 1, .left = NULL, .right = NULL };
	EXPECT_TRUE(isBalanced(&root));
}