// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
61. 旋转链表

https://leetcode-cn.com/problems/rotate-list/description/

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是根据链表的长度和K值确定实际需要平移的长度，然后找到待平移的尾链表，
重新组织链表结构。
*/
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL)
			return head;
		int num = 1;
		ListNode* current = head;
		while (current->next) {				//确定链表长度
			++num;
			current = current->next;
		}
		int actual_k = k%num;				//确定实际平移长度
		ListNode* last = current;			//标记平移链表尾节点
		current = head;
		int index = 1;
		while (index != num - actual_k) {	//找到待平移尾链表的前一节点
			current = current->next;
			++index;
		}
		last->next = head;					//尾链表的末尾指向原链表的头
		head = current->next;				//原链表的头指向尾链表的头
		current->next = NULL;				//原链表的尾指向尾链表的尾(即为NULL)

		return head;
	}
};
