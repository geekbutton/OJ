// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
99. 恢复二叉搜索树
https://leetcode-cn.com/problems/recover-binary-search-tree/description/

二叉搜索树中的两个节点被错误地交换。
请在不改变其结构的情况下，恢复这棵树。

进阶:
	使用 O(n) 空间复杂度的解法很容易实现。
	你能想出一个只使用常数空间的解决方案吗？
*/

/*整体思路是 :	使用O(n)复杂度的方法很容易，使用二叉遍历的方式将结果存入数组，找出不是递增
序的元素进行交换。若要使用常数空间其实还是使用中序遍历的性质，只是每次只保存前一元素节点，
将前一元素节点与当前节点元素比较，记录下呈递减序的两个节点。注意递减序的两个节点只保存第一次
递减序时的第一个节点同时每次更新第二个节点(即找到最后一个递减序的第二个节点)，同时交换时只交
换两个树节点中的值。
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
void Inorder(TreeNode*, vector<TreeNode*>&, TreeNode**);
class Solution {
public:
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> result(2, NULL);	//记录待交换节点
		TreeNode* tempNode = NULL;
		TreeNode** last = &tempNode;
		Inorder(root, result, last);
		//交换找到的节点
		int temp = result[0]->val;
		result[0]->val = result[1]->val;
		result[1]->val = temp;
	}
};
//依旧是中序遍历，只是每次保存前一节点，令其和当前节点比较，记录待交换的节点
void Inorder(TreeNode* root, vector<TreeNode*>& result, TreeNode** last) {
	if (root->left != NULL)
		Inorder(root->left, result, last);
	if (*last != NULL) {
		if ((*last)->val > root->val) {
			if (result[0] == NULL)	//比较前一节点和当前节点的值，只在第一次更新result[0]
				result[0] = (*last);	//但是每次满足条件都要更新result[1]
			result[1] = root;
		}
	}
	(*last) = root;		//每次更新last节点，注意它是一个二级指针
	if (root->right != NULL)
		Inorder(root->right, result, last);
	return;
}