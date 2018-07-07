// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
124. 二叉树中的最大路径和
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/

给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。
该路径至少包含一个节点，且不一定经过根节点。
*/

/*整体思路是 :	利用分治算法，递归地对左右节点分别求解，最后进行组合。需要注意的是递归函数
的返回值和最大路径的更新规则。
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
int Sum(TreeNode*, int&);
class Solution {
public:
	int maxPathSum(TreeNode* root) {
		int result = root->val;		//首先另result为根节点值，避免后续出现负值时可能导致的问题
		Sum(root, result);
		return result;
	}
};
//递归函数
int Sum(TreeNode* root, int& result) {
	int left = 0, right = 0;
	//分别对左右节点递归求解
	if (root->left)
		left = Sum(root->left, result);
	if (root->right)
		right = Sum(root->right, result);

	//注意这里分出的情况主要是针对可能出现的负值对求解最大值时和0比较带来的错误
	//1.该节点为叶节点，则最大值为 max(result, root->val)
	if (!root->left && !root->right)
		result = max(result, root->val);
	//2.该节点左右子节点都存在，则最大值可能为result，root->val + left，root->val + right
	//及left + right + root->val或left，right
	else if (root->left && root->right)
		result = max(result, max(max(root->val + left, root->val + right), max(max(left, right), left + right + root->val)));
	//3.只有左子节点，则最大值可能是result，root->val，left + root->val，left
	else if (root->left)
		result = max(result, max(root->val, max(left, left + root->val)));
	//4.只有右子节点，则最大值可能是result，root->val，right及right + root->val
	else if (root->right)
		result = max(result, max(root->val, max(right, right + root->val)));
	//需要注意的是，无论最大路径是什么，当前根节点返回的最大值只可能包含当前根节点的一条
	//到子节点的路径，因此返回值的取值是root->val，root->val + left及root->val + right中的最大值
	return max(root->val, max(root->val + left, root->val + right));
}