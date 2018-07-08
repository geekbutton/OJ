// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
145. 二叉树的后序遍历
https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/

给定一个二叉树，返回它的 后序 遍历。
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

/*整体思路是 :	递归的方式很容易实现，因此此处只采用迭代算法完成。类似于习题94,144，迭代算法的
关键在于使用栈，将尚未处理完成的数据推入栈中以供迭代。考虑后序遍历的左右根顺序，不能像前序和中序
那样简单的将根元素插入栈，因为会造成左子树或右子树重复处理的问题。因此考虑两种解决方案，一种
是采用一个标记表示该节点的右子树是否已被访问，若是则直接跳过。另一种解决方案是按照根右左的顺序
遍历元素，再将其反序即可得到左右根的后序遍历。此处采用第二种方式。
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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> Ts;
		TreeNode* pre = NULL;
		if (root == NULL)
			return result;
		while (root || Ts.size()) {
			//推入根节点
			result.push_back(root->val);
			if (root->right) {	//先处理右节点
				if (root->left)
					Ts.push(root);
				root = root->right;
			}
			else if (root->left) {
				root = root->left;
			}
			else if (Ts.size()) {
				root = Ts.top()->left;
				Ts.pop();
			}
			else
				break;
		}//最后将结果反序
		reverse(result.begin(), result.end());
		return result;
	}
};