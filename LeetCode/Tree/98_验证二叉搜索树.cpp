// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
98. 验证二叉搜索树
https://leetcode-cn.com/problems/validate-binary-search-tree/description/

给定一个二叉树，判断其是否是一个有效的二叉搜索树。
一个二叉搜索树具有如下特征：
	节点的左子树只包含小于当前节点的数。
	节点的右子树只包含大于当前节点的数。
	所有左子树和右子树自身必须也是二叉搜索树。
*/

/*整体思路是 :	因为此处的二叉树定义中左右根节点中一定不存在相等的点，因此直接采用中序遍历
的方式获取二叉树对应元素序列，则若该二叉树为二叉搜索树则该序列必定为递增序，因此通过判断
该序列是否为递增序列即可判断该二叉树是否是二叉搜索树。
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
void inorderTraversal(TreeNode*, vector<int>&);
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> result;
		if (root == NULL)
			return true;
		inorderTraversal(root, result);
		//遍历中序遍历得到的vector判断其是否为递增序列，是则为二叉搜索树，否则不是
		for (int i = 0; i < result.size() - 1; ++i) {
			if (result[i] >= result[i + 1])
				return false;
		}
		return true;
	}
};
//中序遍历过程，将中序遍历的结果置于vector中
void inorderTraversal(TreeNode* root, vector<int>& result) {
	if (root->left != NULL)
		inorderTraversal(root->left, result);
	result.push_back(root->val);
	if (root->right != NULL)
		inorderTraversal(root->right, result);
}