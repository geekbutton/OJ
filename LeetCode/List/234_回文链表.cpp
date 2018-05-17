// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
234. ��������

https://leetcode-cn.com/problems/palindrome-linked-list/description/
���ж�һ�������Ƿ�Ϊ��������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·���Ƚ�������η�ת��Ȼ���ԭ����ͷ�ת����ͷ��ʼ�Ƚ�Ԫ��
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
		while (count < iter) {						//�ҵ�����ת��������ʼλ��
			current = current->next;
			++count;
		}

		current = Get_solution(current);		//��ת����
		count = 0;
		while (count < iter) {					//��ʼ�Ƚ�Ԫ��
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

ListNode* Get_solution(ListNode* head) {			//��ת������
	if (head == NULL || head->next == NULL)
		return head;
	ListNode* root = Get_solution(head->next);
	head->next->next = head;
	head->next = NULL;
	return root;
}