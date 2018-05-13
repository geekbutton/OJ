// Data_structures.cpp : 定义控制台应用程序的入口点。
//

/*
328. 奇偶链表

https://leetcode-cn.com/problems/odd-even-linked-list/description/
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes为节点总数。
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//整体思路为根据头节点和第二个节点轮流迭代获得他们的下下一个节点，最后将两个链表连接
//即基数链表的下一个元素应为偶链表在原链表中的下一个元素，偶链表的下一个元素为更新后的基链表
//在原链表中的下一个元素。（先更新基链表，再更新偶链表）
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* second = head->next;
		ListNode* current_s = head->next;
		ListNode* current_h = head;
		while (current_h->next->next != NULL && current_s->next->next != NULL) {	//对应的是下下一个
			current_h -> next = current_s->next;
			current_s->next = current_h->next->next;

			current_h = current_h->next;
			current_s = current_s->next;
		}
		if (current_h->next->next == NULL) {
			current_h->next = second;
		}
		else if (current_s->next->next == NULL) {
			current_h->next = current_s->next;
			current_h->next->next = second;

		}
		current_s->next = NULL;
		return head;
	}
};