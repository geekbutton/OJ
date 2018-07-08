// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
109. 有序链表转换二叉搜索树
https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
*/

/*整体思路是 :	原本以为该题涉及到平衡二叉树的转换，后来才想到因为链表有序，因此可以通过简单
的将链表二分从而保证二叉树的左右子树的高度差。做法是将链表二分，取二分节点为根节点，左右两个
链表组成其左右字数，然后通过递归的方式处理左右链表。
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
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
TreeNode* ConstructTree(ListNode*, int);
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int num = 0;
		if (head == NULL)
			return NULL;
		ListNode* current = head;
		//首先统计链表长度，用于快速二分
		while (current) {
			++num;
			current = current->next;
		}
		TreeNode* root = ConstructTree(head, num);
		return root;
	}
};

TreeNode* ConstructTree(ListNode* head, int num) {
	int count = 0;
	ListNode* current = head;
	if (num == 1) {	//处理链表只剩下一个元素的情况
		TreeNode* root = new TreeNode(head->val);
		return root;
	}
	while (count < num / 2) {
		current = current->next;
		++count;
	}
	//得到根节点和其左右链表及左右链表长度
	TreeNode* root = new TreeNode(current->val);
	ListNode* l = head, *r = current->next;
	int l_size = num / 2, r_size = num - count - 1;
	if (l_size)
		root->left = ConstructTree(l, l_size);
	if (r_size)
		root->right = ConstructTree(r, r_size);
	return root;
}
