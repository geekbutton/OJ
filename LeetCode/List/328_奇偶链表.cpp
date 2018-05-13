// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
328. ��ż����

https://leetcode-cn.com/problems/odd-even-linked-list/description/
����һ�������������е������ڵ��ż���ڵ�ֱ�����һ����ע�⣬����������ڵ��ż���ڵ�ָ���ǽڵ��ŵ���ż�ԣ������ǽڵ��ֵ����ż�ԡ�

�볢��ʹ��ԭ���㷨��ɡ�����㷨�Ŀռ临�Ӷ�ӦΪ O(1)��ʱ�临�Ӷ�ӦΪ O(nodes)��nodesΪ�ڵ�������
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//����˼·Ϊ����ͷ�ڵ�͵ڶ����ڵ���������������ǵ�����һ���ڵ㣬���������������
//�������������һ��Ԫ��ӦΪż������ԭ�����е���һ��Ԫ�أ�ż�������һ��Ԫ��Ϊ���º�Ļ�����
//��ԭ�����е���һ��Ԫ�ء����ȸ��»������ٸ���ż����
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* second = head->next;
		ListNode* current_s = head->next;
		ListNode* current_h = head;
		while (current_h->next->next != NULL && current_s->next->next != NULL) {	//��Ӧ��������һ��
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