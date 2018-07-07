// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
129. 求根到叶子节点数字之和
https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/submissions/1

给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。
说明: 叶子节点是指没有子节点的节点。
*/

/*整体思路是 :	利用深度优先搜索的想法遍历所有根节点到叶子结点的组合，将路径上的数字记录为
字符串的形式，最终再将所有字符串变为对应数字进行求和。
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
void Sum(TreeNode*, vector<string>&, string);
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int result = 0;
		vector<string> sv;
		string value;
		if (root == NULL)
			return 0;
		Sum(root, sv, value);
		//对记录的所有路径求和
		for (int i = 0; i < sv.size(); ++i) {
			int temp = stoi(sv[i]);
			result += temp;
		}
		return result;
	}
};
//深度优先搜索遍历所有可能的路径组合，记录为string
void Sum(TreeNode* root, vector<string>& sv, string value) {
	value += to_string(root->val);
	if (root->left)
		Sum(root->left, sv, value);
	if (root->right)
		Sum(root->right, sv, value);
	if (!root->left && !root->right)
		sv.push_back(value);
}