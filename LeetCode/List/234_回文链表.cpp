// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
234. 回文链表

https://leetcode-cn.com/problems/palindrome-linked-list/description/
请判断一个链表是否为回文链表。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*整体思路是先将链表后半段反转，然后从原链表和反转链表头开始比较元素
*/
ListNode* Get_solution(ListNode*);
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		if (head->next->next == NULL) {
			if (head->val == head->next->val)
				return true;
			return false;
		}

		int num = 0;
		ListNode* current = head;
		while (current) {
			++num;
			current = current->next;
		}
		int count = 0;
		int iter = num / 2;
		current = head;
		while (count < iter) {						//找到待反转的链表起始位置
			current = current->next;
			++count;
		}

		current = Get_solution(current);		//反转链表
		count = 0;
		while (count < iter) {					//开始比较元素
			if (head->val == current->val) {	
				++count;
				head = head->next;
				current = current->next;
				continue;
			}
			return false;
		}
		return true;
	}
};

ListNode* Get_solution(ListNode* head) {			//反转链表函数
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* root = Get_solution(head->next);
	head->next->next = head;
	head->next = NULL;
	return root;
}