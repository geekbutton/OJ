// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
142. 环形链表 II

https://leetcode-cn.com/problems/linked-list-cycle-ii/description/

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
说明：不允许修改给定的链表。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*主要思想是设置快慢指针判断是否有环，若有则定位到快慢指针相遇的点。根据相关数学推导可知，
相遇点到环的第一个节点的距离等于链表开头到入环点的距离，此时用两个慢速指针则一定会在入环点相遇。
*/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;

		ListNode* fast = head;
		ListNode* slow = head;
		
		while (fast->next && fast->next->next) {		//快指针是慢指针速度的两倍
			slow = slow->next;
			fast = fast->next->next;
			if (slow != fast)		
				continue;
			//找到了相遇点，慢指针从相遇点开始，快指针从头开始以相同的速度前进
			fast = head;			
			while (slow != fast) {
				fast = fast->next;
				slow = slow->next;
			}
			return slow;
		}
		return NULL;
	}
};