// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
116. 填充同一层的兄弟节点
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/description/

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。
如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

说明:
	你只能使用额外常数空间。
	使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
	你可以假设它是一个完美二叉树（即所有叶子节点都在同一层，每个父节点都有两个子节点）。
*/

/*整体思路是 :	利用递归的方式进行处理，函数的参数表示待处理节点。首先连接待处理节点的左右
子节点，然后判断待处理节点的next节点，若为空则其右子节点的next为空，如不为空则其右子节点的
next为该节点next的左子节点。注意，在这里只处理非叶子节点，对于叶子结点直接跳过。
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
		root->next = NULL;
		connectLevel(root);
	}
};

void connectLevel(TreeLinkNode* root) {
	if (root->left != NULL) {	//只处理非叶子节点
		root->left->next = root->right;	//处理传入节点的左右子节点
		TreeLinkNode* temp = root;
		if (temp->next != NULL)	//处理其右子节点的next节点
			temp->right->next = temp->next->left;
		else
			temp->right->next = NULL;
		//继续递归处理其左右子节点
		connectLevel(root->left);
		connectLevel(root->right);
	}
}