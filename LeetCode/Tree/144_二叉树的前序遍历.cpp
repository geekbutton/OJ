// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
144. 二叉树的前序遍历
https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/

给定一个二叉树，返回它的 前序 遍历。
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/*整体思路是 :	递归的方式很容易实现，因此此处只采用迭代算法完成。类似于习题94，迭代算法的
关键在于使用栈，将尚未处理完成的数据推入栈中以供迭代。
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
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> Ts;
		while (root != NULL || Ts.size()) {
			result.push_back(root->val);		//先序遍历，首先将元素推入结果中
			if (root->left) {		//如果左节点存在，则继续迭代左节点，注意只有当有节点也存在
				if (root->right)	//时才将其推入栈中供后续迭代右节点
					Ts.push(root);
				root = root->left;
			}//若只存在右节点，则迭代右节点
			else if (root->right) {
				root = root->right;
			}
			else if (Ts.size()) {	//迭代至叶子节点则从当前栈中取出元素继续迭代其右子节点
				TreeNode* temp = Ts.top();
				Ts.pop();
				root = temp->right;
			}
			else//对应只有一个节点时的退出条件
				break;
		}
		return result;
	}
};