// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
24. 两两交换链表中的节点

https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* Get_solution(ListNode*);

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* current = head;
		return Get_solution(head);
		
	}
};

//利用迭代的方式求解
ListNode* Get_solution(ListNode* current) {
	//判断是否有两个元素
	if (current != NULL && current->next != NULL) {
		ListNode* result = current->next;		//如果有，则保存第二个元素为返回结果
		ListNode* temp = current->next->next;
		current->next->next = current;
		current->next = Get_solution(temp);		//设定第一个元素的next值，即将前一组链表
		return result;							//与后一组链表连接
	}
	return current;				//如果没有两个元素，则直接返回
}