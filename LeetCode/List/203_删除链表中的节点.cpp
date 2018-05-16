// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
203. ɾ�������еĽڵ�

https://leetcode-cn.com/problems/remove-linked-list-elements/description/
ɾ�������е��ڸ���ֵ val �����нڵ㡣
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*ע�Ȿ��Ҫ�����ɾ�����е���val�Ľڵ㡣�����ж�ͷ�ڵ㣬���ͷ�ڵ㲻�������жϺ����ڵ�
*/
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL)
			return NULL;
		while (head->val == val) {					//�ж�ͷ�ڵ��Ƿ����val,���������ͷ�ڵ�
			ListNode* temp = head;
			head = head->next;
			delete(temp);
			if (head == NULL)
				return NULL;
		}
		ListNode* current = head;	
		while (current->next) {					//�ж�ͷ�ڵ�֮��Ľڵ�
			if (current->next->val != val) {	//���������������һ�ڵ�
				current = current->next;
				continue;
			}
			ListNode* temp = current->next;		//�����ڸ���current.next�ڵ㣬ɾ��ԭnext�ڵ�
			current->next = temp->next;
			delete(temp);
		}
		return head;
	}
};