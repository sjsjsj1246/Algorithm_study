#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct TreeNode
{
	TreeNode* parent;
	vector<TreeNode*> chilren;
};

int dfs(TreeNode* node)
{
	int ret = 0;
	if (node->chilren.empty()) return 1;
	for (auto next : node->chilren)
	{
		ret += dfs(next);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int n;
	TreeNode* root;
	cin >> n;
	vector<TreeNode> tree(n);
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if (temp == -1)
		{
			root = &tree[i];
			continue;
		}
		tree[i].parent = &tree[temp];
		tree[temp].chilren.push_back(&tree[i]);
	}
	int erase;
	cin >> erase;
	if (root == &tree[erase])
	{
		cout << 0;
		return 0;
	}
	tree[erase].parent->chilren.erase(
		find(tree[erase].parent->chilren.begin(),
			 tree[erase].parent->chilren.end(),
			 &tree[erase])
	);
	cout << dfs(root);
}