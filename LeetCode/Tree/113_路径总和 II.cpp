// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
113. 路径总和 II
https://leetcode-cn.com/problems/path-sum-ii/description/

给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
*/

/*整体思路是 :	利用迭代的思路遍历所有根节点到叶子节点的路径，利用一个vector保存路径，
同时记录和值。到叶子结点后判断最终的和是否等于目标值，若是则添加相应路径记录到结果中。
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
void Traversal(TreeNode*, int, int, vector<int>, vector<vector<int>>&);
class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		vector<int> iv;
		int value = 0;
		if (root == NULL)
			return result;
		Traversal(root, sum, value, iv, result);
		return result;
	}
};
//遍历根节点到叶子结点的路径
void Traversal(TreeNode* root, int sum, int value, vector<int>iv, vector<vector<int>>& result) {
	//记录当前根节点
	iv.push_back(root->val);
	value += root->val;
	if (root->left != NULL || root->right != NULL) {
		if (value == sum)		//提前退出
			return;
		if (root->left != NULL)
			Traversal(root->left, sum, value, iv, result);
		if (root->right != NULL)
			Traversal(root->right, sum, value, iv, result);
	}
	else {	//处理到叶子节点，判断路径和是否等于目标值
		if (value == sum) {
			result.push_back(iv);
		}
	}
}