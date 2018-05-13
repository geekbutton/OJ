// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
21. �ϲ�������������

https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
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
		pre->next = l1;						//����һ��������ͷ�����ⵥ���ж�ͷԪ��
		ListNode* head = pre;				//ͬʱ������Ϊ��ǰ��������ǰ�������ڲ������

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