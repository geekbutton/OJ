// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
102. 二叉树的层次遍历
https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
*/

/*整体思路是 :	说到层序遍历首先就应该想到用队列来实现，这里也是一样使用队列来实现，
但不同的是队列中除了节点值外，还存储了节点对应的层次Level用于将相同层的节点置于相同vector中。
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<pair<TreeNode*, int>> Tq;	//定义一个队列来实现层次遍历，其元素包括节点指针和对应Level
		vector<vector<int>> result;
		if (root == NULL)
			return result;
		Tq.push(make_pair(root, 1));
		while (Tq.size()) {
			//首先取出队列中的首元素节点及其level
			TreeNode* node = Tq.front().first;
			int level = Tq.front().second;
			//将该节点的子节点添加到队列中
			if (node->left != NULL)
				Tq.push(make_pair(node->left, level + 1));
			if (node->right != NULL)
				Tq.push(make_pair(node->right, level + 1));
			//将该节点添加至对应result同一层次的vector中
			if (level > result.size()) //新的层需要先在result中插入一个新的vector<int>
				result.push_back(vector<int>());
			result[level - 1].push_back(node->val);
			Tq.pop();	//删除队列头元素，继续处理下一个节点
		}

		return result;
	}
};