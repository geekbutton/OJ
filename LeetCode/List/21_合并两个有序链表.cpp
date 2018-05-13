// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
21. 合并两个有序链表

https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode* pre = new ListNode(0);
		pre->next = l1;						//定义一个空链表头，避免单独判断头元素
		ListNode* head = pre;				//同时保持其为当前插入对象的前驱，便于插入操作

		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				pre = l1;
				l1 = l1->next;
				continue;
			}
			ListNode* temp = l2->next;
			l2->next = l1;
			pre->next = l2;
			pre = pre->next;
			l2 = temp;
		}
		if (l1 == NULL) {
			pre->next = l2;
		}
		return head->next;
	}
};