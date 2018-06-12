// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
105. 从前序与中序遍历序列构造二叉树
https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
	你可以假设树中没有重复的元素。
*/

/*整体思路是 :	利用递归的想法解决。对于前序遍历，首元素即为根元素。从中序遍历中找到该元素，
其左边的所有元素为该节点的左子树的节点，右元素为该节点的右子树的节点，同时前序遍历先遍历完
该节点的左子树上的所有节点，在遍历右子树上的所有节点。因此可以根据中序遍历中左右子树节点的数目
找到所有左右节点的元素，将其分为两个新的中序序列和前序序列，递归求解直至序列中只有一个元素，
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)
			return NULL;
		return BuildTree(preorder, inorder);
	}
};

TreeNode* BuildTree(vector<int>&preorder, vector<int>& inorder) {
	//序列只包含一个元素，则为叶节点，创建叶节点后返回
	if (preorder.size() == 1) {
		TreeNode* node = new TreeNode(preorder[0]);
		return node;
	}
	TreeNode* root = new TreeNode(preorder[0]);			//本次迭代的根节点，对应非叶节点
	auto iter_in = find(inorder.begin(), inorder.end(), preorder[0]);	//找到根元素的位置
	//如果其仍有左子树，则获取其左子树，继续迭代
	if (iter_in != inorder.begin()) {
		//左子树元素该元素中序序列位置的左边，紧跟着该元素在前序序列的后面
		vector<int> left_in(inorder.begin(), iter_in);
		vector<int> left_pre(preorder.begin() + 1, preorder.begin() + 1 + left_in.size());
		root->left = BuildTree(left_pre, left_in);
	}//如果仍有右子树，则获取其右子树，继续迭代
	if (iter_in != inorder.end() - 1) {
		//左子树元素该元素中序序列位置的右边，可从前序序列的最后根据元素数目反推
		vector<int> right_in(iter_in + 1, inorder.end());
		vector<int> right_pre(preorder.end() - right_in.size(), preorder.end());
		root->right = BuildTree(right_pre, right_in);
	}
	return root;
}