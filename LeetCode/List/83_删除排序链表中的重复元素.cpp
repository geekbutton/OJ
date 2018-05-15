// Data_structures.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
83. ɾ�����������е��ظ�Ԫ��

https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
����һ����������ɾ�������ظ���Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Ρ�

*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/*����˼·�Ǵ�head��ʼ�ж�head������һ��Ԫ��ֵ�Ƿ���ȣ�������ȵ�ǰλ���ƶ�һλ
�������ɾ����ǰ�ڵ����һ���ڵ㣬��ǰ�ڵ�λ�ò��䡣
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* current = head;
		while (current && current->next) {
			if (current->val != current->next->val) {		//��������ƶ�����һ���ڵ�
				current = current->next;
				continue;
			}
			ListNode* temp = current->next;					//�����ı�nextԪ�ز�ɾ��
			current->next = current->next->next;
			delete(temp);									//ɾ��nextλ�õĽڵ�
		}
		return head;
	}
};