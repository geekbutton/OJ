// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
114. 二叉树展开为链表
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/

给定一个二叉树，原地将它展开为链表。
此处展开使用的是先序遍历的方式
*/

/*整体思路是 :	利用递归的方式将有左子树的节点其左子节点置为其右子节点，再将其右子节点
连接在当前右子节点的右节点上。
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
class Solution {
public:
	void flatten(TreeNode* root) {
		if (!root)
			return;
		if (root->left != NULL)
			flatten(root->left);
		if (root->right != NULL)
			flatten(root->right);
		TreeNode* temp_right = root->right;
		root->right = root->left;
		root->left = NULL;
		//注意这里的实现保证了即使没有左子节点，右子节点也会被置于正确的位置
		while (root->right != NULL)
			root = root->right;
		root->right = temp_right;
	}
};