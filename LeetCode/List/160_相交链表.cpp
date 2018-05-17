// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
160. 相交链表

https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
编写一个程序，找到两个单链表相交的起始节点。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*非常典型的考题，主要思路是如果两个链表有交点，则遍历A后遍历B，遍历B后遍历A时一定会相遇
*/
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* head1 = headA, *head2 = headB;
		if (headA == NULL || headB == NULL)
			return NULL;
		int count = 3;						//设置退出条件，如果分辨遍历完AB两个链表后还没有相遇，这说明不相交
		while (count) {
			while (head1 && head2) {
				if (head1 == head2)		//相遇则直接返回
					return head1;
				head1 = head1->next;
				head2 = head2->next;
			}
			if (head1 == NULL) {		//A遍历完后从B开始遍历
				head1 = headB;
				--count;
			}
			else if (head2 == NULL) {	//B遍历完后从A开始遍历
				head2 = headA;
				--count;
			}
		}

		return NULL;					//执行到该处说明不存在交点，返回空
	}
};