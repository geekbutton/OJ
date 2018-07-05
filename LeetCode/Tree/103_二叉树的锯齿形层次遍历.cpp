// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
103. 二叉树的锯齿形层次遍历
https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，
再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。根节点为从左往右。
*/

/*整体思路是 :	先用102题的方法获得层序遍历，再将偶数层(根节点为第一层)的result vector
进行翻转即可实现从右往左的遍历。
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
		//相较于普通的层序遍历，就是额外对偶数行的结果进行了翻转
		for (int i = 1; i < result.size(); i += 2) {
			reverse(result[i].begin(), result[i].end());
		}

		return result;
	}
};