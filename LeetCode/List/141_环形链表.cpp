// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
141. 环形链表

https://leetcode-cn.com/problems/linked-list-cycle/description/
给定一个链表，判断链表中是否有环。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*经典链表操作，利用了龟兔赛跑的思想，定义两个指针，两个指针的前进速度不同，如果链表存在
环，则两个指针一定会碰面，否则一个指针会提前走到NULL。
*/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return false;
		ListNode* slower = head;					//慢速指针
		ListNode* faster = head->next;				//快速指针，两个指针起点不同
		while (slower!=faster) {
			//判断是否会有指针走到了NULL
			if (faster->next == NULL || faster->next->next==NULL)
				return false;
			slower = slower->next;					//慢速指针一次移动一个位置
			faster = faster->next->next;			//快速指针一次移动两个位置

		}

		return true;
	}
};