#include <stack>
#include <vector>

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

vector<int> dfs_inorder(TreeNode * node)
{
	stack<TreeNode *, vector<TreeNode *>> stack;
	vector<int> result {};

	while (!stack.empty() || node != nullptr) {
		if (node != nullptr) {
			stack.push(node);
			node = node->left;
		} else {
			node = stack.top();
			stack.pop();
			result.push_back(node->val);
			node = node->right;
		}
	}
	return result;
}