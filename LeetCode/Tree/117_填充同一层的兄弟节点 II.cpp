// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
117. 填充同一层的兄弟节点 II
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/description/

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

说明:
	你只能使用额外常数空间。
	使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/

/*整体思路是 :	这道题看上去和116很相似，区别只是在于本题没有满二叉树这个条件，但正是这个条件
影响了本题的解答。因为不是一颗满二叉树，因此有可能出现某个节点的next是上层节点的非下一next的
子节点，因此就要求在求该节点的next节点时其上层所有节点的next节点都应该处理完成。因此很容易想到
利用层序遍历的方式处理。在这里按照层序遍历的方式对每一层节点的next节点求解。
*/
/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  TreeLinkNode *left, *right, *next;
*  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
* };
*/
void connectLevel(TreeLinkNode*);
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*> Tq;
		Tq.push(root);
		while (Tq.size()) {	//利用一个队列进行层序遍历求解next节点
			TreeLinkNode* temp = Tq.front();
			connectLevel(temp);
			if (temp->left)
				Tq.push(temp->left);
			if (temp->right)
				Tq.push(temp->right);
			Tq.pop();
		}
	}
};
//注意这只是一个普通的函数，不是递归函数
void connectLevel(TreeLinkNode* root) {
	//如果左右节点都不为空，首先连接左右节点
	if (root->left != NULL && root->right != NULL) {
		root->left->next = root->right;
	}//否则，若左节点不为空则处理左节点的next
	else if (root->left != NULL) {
		TreeLinkNode* temp = root->next;
		while (temp) {//注意这里使用的是while而非116题中的if，因为要一直找到下一个非叶子结点
			if (temp->left == NULL && temp->right == NULL)
				temp = temp->next;
			else if (temp->left != NULL) {
				root->left->next = temp->left;
				break;
			}
			else if (temp->right != NULL) {
				root->left->next = temp->right;
				break;
			}
		}
		if (!temp)		//如果没找到就置next为NULL
			root->left->next = NULL;
	}
	if (root->right != NULL) {			//同上面的解答方式
		TreeLinkNode* temp = root->next;
		while (temp) {
			if (temp->left == NULL && temp->right == NULL)
				temp = temp->next;
			else if (temp->left != NULL) {
				root->right->next = temp->left;
				break;
			}
			else if (temp->right != NULL) {
				root->right->next = temp->right;
				break;
			}
		}
		if (!temp)
			root->right->next = NULL;
	}
}