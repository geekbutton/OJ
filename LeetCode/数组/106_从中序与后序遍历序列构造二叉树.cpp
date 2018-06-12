// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
106. 从中序与后序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

根据一棵树的中序遍历与后序遍历构造二叉树。
注意:
	你可以假设树中没有重复的元素。
*/

/*整体思路是 :	利用递归的想法解决。对于后序遍历，尾元素即为根元素。从中序遍历中找到该元素，
其左边的所有元素为该节点的左子树的节点，右元素为该节点的右子树的节点，同时后序遍历先遍历完
该节点的左子树上的所有节点，在遍历右子树上的所有节点。因此可以根据中序遍历中左右子树节点的数目
找到所有左右节点的元素，将其分为两个新的中序序列和后序序列，递归求解至序列中只有一个元素，
此时认为该元素为叶子节点，返回。
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
TreeNode* BuildTree(vector<int>&, vector<int>&);
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)
			return NULL;
		return BuildTree(inorder, postorder);
	}
};

TreeNode* BuildTree(vector<int>& inorder, vector<int>& postorder) {
	int num = postorder.size();
	TreeNode* root = new TreeNode(postorder[num - 1]);
	if (inorder.size() == 1) {
		return root;
	}
	auto iter = find(inorder.begin(), inorder.end(), root->val);
	if (iter != inorder.begin()) {
		vector<int> left_in(inorder.begin(), iter);
		//跟前序的区别在于左子树的元素是从后序序列的头开始的
		vector<int> left_post(postorder.begin(), postorder.begin() + left_in.size());
		root->left = BuildTree(left_in, left_post);
	}
	if (iter != inorder.end() - 1) {
		vector<int> right_in(iter + 1, inorder.end());
		//跟前序的区别在于右子树的元素截止置后序序列的尾元素之前
		vector<int> right_post(postorder.end() - right_in.size() - 1, postorder.end() - 1);
		root->right = BuildTree(right_in, right_post);
	}
	return root;
}